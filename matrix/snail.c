#include <stdio.h>
#define N 7
int main()
{

    int num = 1;
    int matrix[N][N];
    int i = 0;
    int j = 0;
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < N; k = k + 2)
    {
        j = counter;
        i = counter;
        while (j < N - counter - 1)
        {
            matrix[i][j] = num;
            num++;
            j++;
        }
        while (i < N - counter)
        {
            matrix[i][j] = num;
            num++;
            i++;
        }
        i--;
        j--;
        while (j >= counter)
        {
            matrix[i][j] = num;
            num++;
            j--;
        }
        counter++;
        j++;
        i--;
        while (i >= counter)
        {
            matrix[i][j] = num;
            num++;
            i--;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}