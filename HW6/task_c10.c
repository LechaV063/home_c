#include <stdio.h>

// Составить функцию, печать всех простых множителей числа.
// Использовать ее для печати всех простых множителей числа.

void print_simple(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    print_simple(userNumber);
    return 0;
}

void print_simple(int n)
{
    int i = 2;
    if (n == 0)
    {
        printf("0\n");
        return;
    }
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    while (n > 1)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
            n /= i;
        }
        else
        {
            i++;
        }
    }
    printf("\n");
    return;
}