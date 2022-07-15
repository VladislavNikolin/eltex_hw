#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

void add();
void divide();
void multiply();
void sub();

int firstNumber;
int secondNumber;
int result;

void main()
{

    int choice;

    while (1)
    {
        printf("Welcome to the calc! \n");
        printf("If you want to add 2 numbers, press 1 \n");
        printf("If you want to divide 2 numbers, press 2 \n");
        printf("If you want to multiply 2 numbers, press 3 \n");
        printf("If you want to carry out a subtraction operation, press 4 \n");
        printf("If you want to exit the calc, press 5 \n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            divide();
            break;
        case 3:
            multiply();
            break;
        case 4:
            sub();
            break;
        case 5:
            exit(0);
        }
    }
}

void add()
{
    printf("Print 2 numbers");
    scanf("%d %d", &firstNumber, &secondNumber);
    result = addition(firstNumber, secondNumber);
    printf("%d", result);
}

void divide()
{
    printf("Print 2 numbers");
    scanf("%d %d", &firstNumber, &secondNumber);
    result = division(firstNumber, secondNumber);
    printf("%d", result);
}

void multiply()
{
    printf("Print 2 numbers");
    scanf("%d %d", &firstNumber, &secondNumber);
    result = multiplication(firstNumber, secondNumber);
    printf("%d", result);
}

void sub()
{
    printf("Print 2 numbers");
    scanf("%d %d", &firstNumber, &secondNumber);
    result = subtraction(firstNumber, secondNumber);
    printf("%d", result);
}




