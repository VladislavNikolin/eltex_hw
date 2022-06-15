#include <stdio.h>
#define N 10
int main()
{
    int matrix[N][N];
    int k = 0;
    int n = N - 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = 1;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (k == n)
            {
                n--;
                k = 0;
                break;
            }
            else
            {
                matrix[i][j] = 0;
                k++;
            }
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