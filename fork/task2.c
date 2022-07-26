#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
{
    pid_t pid[5];
    pid[0] = fork();

    if (pid[0] == 0)
    {
        printf("2 pid = %d\n", getpid());
        printf("2 ppid = %d\n", getppid());
        pid[1] = fork();

        if (pid[1] == 0)
        {
            printf("4 pid = %d\n", getpid());
            printf("4 ppid = %d\n", getppid());
            exit(EXIT_SUCCESS);
        }
        else
        {
            waitpid(pid[1], 0, 0);
            exit(EXIT_SUCCESS);
        }
    }
    else
    {
        printf("1 pid = %d\n", getpid());
        printf("1 ppid = %d\n", getppid());
        pid[2] = fork();
        if (pid[2] == 0)
        {
            printf("3 pid = %d\n", getpid());
            printf("3 ppid = %d\n", getppid());
            pid[3] = fork();
            if (pid[3] == 0)
            {
                printf("5 pid = %d\n", getpid());
                printf("5 ppid = %d\n", getppid());
                exit(EXIT_SUCCESS);
            }
            else
            {
                pid[4] = fork();
                if (pid[4] == 0)
                {
                    printf("6 pid = %d\n", getpid());
                    printf("6 ppid = %d\n", getppid());
                    exit(EXIT_SUCCESS);
                }
                else
                {
                    waitpid(pid[3], 0, 0);
                    waitpid(pid[4], 0, 0);
                    exit(EXIT_SUCCESS);
                }
            }
        }
        else
        {
            waitpid(pid[2], 0, 0);
            waitpid(pid[0], 0, 0);
            exit(EXIT_SUCCESS);
        }
    }
}