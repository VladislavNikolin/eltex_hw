#include <stdio.h>

int main()
{
    struct test1
    {
        char a;
        int b;
    };

    struct test2
    {
        int c;
        char d;
        char g;
        char h;
        char i;
        char j;
    };

    struct test3
    {
        char e;
        int f;
        int k;
    } __attribute__((packed));

    int size1 = sizeof(struct test1);
    printf("length of first structure %d\n", size1);

    int size2 = sizeof(struct test2);
    printf("length of second structure %d\n", size2);

    int size3 = sizeof(struct test3);
    printf("length of third structure %d\n", size3);

    struct test1 test1;
    struct test2 test2;
    struct test3 test3;

    test1.a = 'A';
    test1.b = 12345;

    test2.c = 12345;
    test2.d = 'D';
    test2.g = 'G';
    test2.h = 'H';
    test2.i = 'I';
    test2.j = 'J';

    test3.e = 'E';
    test3.f = 12345;
    test3.k = 12345;

    char *ptr1;
    char *ptr2;
    char *ptr3;

    ptr1 = &test1;
    ptr2 = &test2;
    ptr3 = &test3;

    for (int i = 0; i < size1; i++)
    {
        printf("%3d", *ptr1);
        ptr1++;
    }
    printf("\n");
    for (int i = 0; i < size2; i++)
    {
        printf("%3d", *ptr2);
        ptr2++;
    }
    printf("\n");
    for (int i = 0; i < size3; i++)
    {
        printf("%3d", *ptr3);
        ptr3++;
    }
    printf("\n");
}