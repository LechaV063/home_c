#include <stdio.h>
// Условие:
// Перевести натуральное число в двоичную систему счисления.
// Необходимо реализовать рекурсивную функцию.
// Входные данные: Целое не отрицательное число в десятичной системе счисления
// Выход: Целое число в двоичной системе счисления

void convert(int n);

int main(int argv, char **argc)
{
    unsigned int userNumber;
    scanf("%u", &userNumber);
    convert(userNumber);
    printf("\n");
    return 0;
}

void convert(int n)
{
    if (n / 2 == 0)
    {
        printf("%d", n%2);
        return;
    }
    convert(n / 2);
    printf("%d", n % 2);
    return;
}