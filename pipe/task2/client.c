#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PIPE_NAME "chat"
#define BUFFER_SIZE 255

int main()
{
    int fd;
    mkfifo(PIPE_NAME, 0666);
    char response[BUFFER_SIZE], request[BUFFER_SIZE];

    printf("You are the client, please write the message to start a conversation \n");
    while (1)
    {
        fd = open(PIPE_NAME, O_WRONLY);
        printf("> ");
        fgets(request, BUFFER_SIZE, stdin);
        write(fd, request, strlen(request)+1);
        close(fd);
        fd = open(PIPE_NAME, O_RDONLY);
        read(fd, response, sizeof(response));
        printf("RESPONSE: %s", response);
        close(fd);
    }
    return 0;
}