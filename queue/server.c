#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#ifndef KEY_PATH
#define KEY_PATH "key.txt"
#endif // KEY_PATH

#define PROJECT_ID 1337
#define BUFFER_SIZE 255

int main(void)
{
    // create key
    int key = ftok(KEY_PATH, PROJECT_ID);
    if (key == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // create queue
    int queue_id = msgget(key, IPC_CREAT | 0660);
    if (queue_id == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // main loop
    printf("You are the server, please wait for the client to start a conversation \n");
    while (1)
    {
        char request[BUFFER_SIZE], response[BUFFER_SIZE];

        // receive message from the client
        if (msgrcv(queue_id, request, sizeof(typeof(request)), 0, 0) == -1)
        {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }
        printf("REQUEST: %s \n", request);

        // send message to the client
        printf("> ");
        fgets(response, BUFFER_SIZE, stdin);

        if (!strcmp(response, "\n"))
            break;

        if (msgsnd(queue_id, response, sizeof(typeof(response)), 0) == -1)
        {
            perror("msgget");
            exit(EXIT_FAILURE);
        }
    }

    // delete queue
    if (msgctl(queue_id, IPC_RMID, NULL) == -1)
    {
        perror("client: msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
