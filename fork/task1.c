#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    pid_t pid = 0;
    pid = fork();

    if (pid == 0)
    {
        printf("Child pid: %d\n", getpid());
        printf("Child ppid: %d\n", getppid());
    }
    else
    {
        printf("Parent pid: %d\n", getpid());
        printf("Parent pid: %d\n", getppid());
    }
}