//Справочник функции+
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define VOLUME 10

struct entry
{
    char name[25];
    char surname[25];
    int number;
};

void add(struct entry *);
void search(struct entry *);
void list(struct entry *);
void delete (struct entry *);



int main(void)
{
    int choice;

    struct entry *phonebook = calloc(VOLUME, sizeof(struct entry));
   

    for (int i = 0; i < VOLUME; i++)
    {
        phonebook[i].number = 0;
        phonebook[i].name[0] = '\0';
        phonebook[i].surname[0] = '\0';
    }

    while (1)
    {
        printf("Welcome to the subscriber directory! \n");
        printf("If you want to  add a new subscriber, press 1 \n");
        printf("If you want to find a subscriber, press 2 \n");
        printf("If you want to see the list of subscribers, press 3 \n");
        printf("If you want to delete a subscriber, press 4 \n");
        printf("If you want to exit the subscriber directory, press 5 \n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add(phonebook);
            break;
        case 2:
            search(phonebook);
            break;
        case 3:
            list(phonebook);
            break;
        case 4:
            delete (phonebook);
            break;
        case 5:
            return 0;
        }
    }
}

void add(struct entry *phonebook)
{
    for (int i = 0; i < VOLUME; i++)
    {
        if (phonebook[i].number == 0)
        {
            printf("Enter subscriber's name \n");
            scanf("%s", &phonebook[i].name);
            printf("Enter subscriber's surname \n");
            scanf("%s", &phonebook[i].surname);
            printf("Enter subscriber's number \n");
            scanf("%d", &phonebook[i].number);
            break;
        }
    }
}

void search(struct entry *phonebook)
{
    int searchByNumber = 0;
    printf("Enter subscriber's number ");
    scanf("%d", &searchByNumber);
    for (int i = 0; i < VOLUME; i++)
    {
        if (phonebook[i].number == searchByNumber)
        {
            printf("subscriber's name %s \n", phonebook[i].name);
            printf("subscriber's surname %s \n", phonebook[i].surname);
            printf("subscriber's number %d \n", phonebook[i].number);
            break;
        }
    }
}

void list(struct entry *phonebook)
{
    for (int i = 0; i < VOLUME; i++)
    {
        if (phonebook[i].number != 0)
        {

            printf("subscriber's name %s \n", phonebook[i].name);
            printf("subscriber's surname %s \n", phonebook[i].surname);
            printf("subscriber's number %d \n", phonebook[i].number);
        }
    }
}

void delete (struct entry *phonebook)
{
    int deleteByNumber = 0;
    printf("Enter subscriber's number ");
    scanf("%d", &deleteByNumber);
    for (int i = 0; i < VOLUME; i++)
    {
        if (phonebook[i].number == deleteByNumber)
        {
            phonebook[i].number = 0;
            phonebook[i].name[0] = '\0';
            phonebook[i].surname[0] = '\0';
        }
    }
}