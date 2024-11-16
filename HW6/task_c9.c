#include <stdio.h>

//  Составить функцию вычисления N!.
// Использовать ее при вычислении факториала

int factorial(int n);

int main(int argv, char **argc)
{
    int number;
    scanf("%d", &number);
    if (number <= 20) {
        printf("%u\n", factorial(number));
    }
    return 0;
}

int factorial(int n)
{
    unsigned int result = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
    }
    return result;
}