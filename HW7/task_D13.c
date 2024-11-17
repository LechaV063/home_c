#include <stdio.h>
// Условие:
// Составить рекурсивную функцию, печать всех простых множителей числа.
//
// Входные данные: Натуральное число
// Выход: Последовательность из всех простых делителей числа через пробел

//
void print_simple(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    if (userNumber == 0 || userNumber == 1)
    {
        return 0;
    }
    print_simple(userNumber);
    printf("\n");
    return 0;
}

void print_simple(int n)
{
    static int devider = 2;
    if (n == 1)
    {
        return;
    }
    if (n % devider != 0)
    {
        devider++;
        print_simple(n);
    }
    else
    {
        printf("%d ", devider);
        print_simple(n / devider);
    }

    return;
}