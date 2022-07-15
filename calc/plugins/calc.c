//Калькулятор плагины
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <malloc.h>
#include <dirent.h>
#include <string.h>

typedef int (*operator_t)(int firstNumber, int secondNumber);

struct plugin
{
    char *name;
    operator_t operator;
    void *handle;
};

struct plugin *loadPlugins(const char *dir, int *pluginCount)
{
    DIR *folder = opendir("./plugins");
    struct plugin *plugins = NULL;
    int count = 0;

    for (struct dirent *entry; entry = readdir(folder);)
    {
        char *libName = entry->d_name;
        if (!strcmp(libName + strlen(libName) - 3, ".so"))
        {
            plugins = realloc(plugins, (count + 1) * sizeof(struct plugin));
            char *path = calloc(strlen(libName) + strlen("./plugins/") + 1, sizeof(char));
            strcat(path, "./plugins/");
            strcat(path, libName);
            void *handle = dlopen(path, RTLD_LAZY);
            char **name = dlsym(handle, "name");
            operator_t operator= dlsym(handle, *name);
            plugins[count].name = *name;
            plugins[count].operator= operator;
            plugins[count].handle = handle;
            count++;
            free(path);
        }
    }
    *pluginCount = count;

    return plugins;
}

void unloadPlugins(struct plugin *plugins, int pluginCount)
{
    for (int i = 0; i < pluginCount; i++)
        dlclose(plugins[i].handle);
    free(plugins);
}

int menu(struct plugin *plugins, int pluginCount)
{
    int choice;

    printf("Welcome to the calc! \n");
    printf("If you want to exit the calc, press 0 \n");
    printf("Choose the plugin you want to use: \n");
    for (int i = 0; i < pluginCount; i++)
        printf("%d. %s  \n", (i + 1), plugins[i].name);
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void main()
{
    int pluginCount = 0;
    struct plugin *plugins = loadPlugins("./plugins", &pluginCount);

    for (int choice; choice = menu(plugins, pluginCount);)
    {
        int pluginIndex = choice - 1;
        int firstNumber = 0;
        int secondNumber = 0;

        printf("Enter two operands: ");
        scanf("%d %d", &firstNumber, &secondNumber);
        printf("Result: %d \n", plugins[pluginIndex].operator(firstNumber, secondNumber));
        printf("\n");
    }

    unloadPlugins(plugins, pluginCount);
}