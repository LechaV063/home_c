#include <stdio.h>

// Составить функцию, которая определяет наибольший общий делитель
// двух натуральных и привести пример ее использования.

int nod(int a, int b);

int main(int argv, char **argc)
{
    int numberA, numberB, minDivider;
    scanf("%d %d", &numberA, &numberB);
    printf("%d\n", nod(numberA, numberB));
    return 0;
}

int nod(int a, int b)
{
    int minDivider;
    while (b != 0)
    {
        minDivider = b;
        b = a % b;
        a = minDivider;
    }
    return minDivider;
}
