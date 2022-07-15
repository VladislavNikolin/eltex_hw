#include <stdio.h>
#include <stdlib.h>
int division(int firstNumber, int secondNumber)
{
    int result;
    if (secondNumber == 0)
    {
        printf("Error: attempt to divide by 0 \n");
        exit(1);
    }
    else
    {
        result = firstNumber / secondNumber;
    }
    return result;
}