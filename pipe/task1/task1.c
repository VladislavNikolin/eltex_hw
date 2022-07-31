
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void main(int argc, char **argV)
{
    if (argc < 2){
        printf("Error");
        exit(EXIT_FAILURE);
    }

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = 0;
    char buf = '1';

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        close(fd[1]);
        while (read(fd[0], &buf, 1) > 0)
        {
            write(STDOUT_FILENO, &buf, 1);
        }
        write(STDOUT_FILENO, "\n", 1);
        close(fd[0]);

        exit(EXIT_SUCCESS);
    }
    else
    {
        close(fd[0]);
        write(fd[1], argV[1], strlen(argV[1]));
        close(fd[1]);
        wait(NULL);

        exit(EXIT_SUCCESS);
    }
}
