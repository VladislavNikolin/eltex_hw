#include <stdio.h>
#define N 4

int main()
{

    int number = 1;
    int matrix[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = number;
            number++;
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
