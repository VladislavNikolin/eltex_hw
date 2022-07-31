#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_worker(void *)
{
    sigset_t set;
    int sig;

    while (1)
    {
        sigemptyset(&set);
        sigaddset(&set, SIGUSR1);
        sigwait(&set, &sig);
        if (sig == SIGUSR1)
            printf("Сигнал получен \n");
    }
}

void main()
{
    pthread_t handler;

    if (pthread_create(&handler, NULL, thread_worker, NULL) < 0)
    {
        perror("create failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        sleep(1);
        if (pthread_kill(handler, SIGUSR1) < 0)
            exit(EXIT_FAILURE);
    }
}