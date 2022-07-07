//Справочник
#include <stdio.h>
#define VOLUME 10

int main(void)
{
    int choice;
    int searchByNumber;
    int deleteByNumber;

    struct entry
    {
        char name[25];
        char surname[25];
        int number;
    };
    struct entry phonebook[VOLUME];

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
            break;
        case 2:
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
            };
            break;
        case 3:
            for (int i = 0; i < VOLUME; i++)
            {
                if (phonebook[i].number != 0)
                {

                    printf("subscriber's name %s \n", phonebook[i].name);
                    printf("subscriber's surname %s \n", phonebook[i].surname);
                    printf("subscriber's number %d \n", phonebook[i].number);
                }
            }
            break;
        case 4:
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
            break;
        case 5:
            return 0;
        }
    }
}