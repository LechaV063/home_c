#include <stdio.h>

// Составить программу для вычисления НОД с помощью алгоритма Евклида.
// Даны два натуральных числа. Найти наибольший общий делитель.

int main(int argv, char **argc)
{
    int numberA, numberB, minDivider;
    scanf("%d %d", &numberA, &numberB);
    while (numberB != 0) 
    {
        minDivider = numberB;
        numberB = numberA % numberB;
        numberA = minDivider;
    }
    printf("%d\n", numberA);
    return 0;    
}