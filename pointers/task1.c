#include <stdio.h>

int main()
{
    int a = 270533154;
    char *ptr;

    ptr = &a;

    printf("first byte of a = %d\n", *ptr);
    ptr++;
    printf("second byte of a = %d\n", *ptr);
    ptr++;
    printf("third byte of a = %d\n", *ptr);
    *ptr = 0;
    printf("new third byte of a = %d\n", *ptr);
    ptr++;
    printf("fourth byte of a = %d\n", *ptr);
}