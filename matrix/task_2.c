#include <stdio.h>
#define N 40

int main()
{

    int array[N];
    int num = 1;

    for (int i = 0; i < N; i++)
    {
        array[i] = num;
        num++;
    }

    int swap;
    int left = 0;
    int right = N - 1;

    while (left < right)
    {
        swap = array[left];
        array[left] = array[right];
        array[right] = swap;
        left = left + 1;
        right = right - 1;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%3d ", array[i]);
    }

    printf("\n");
}