#include <stdio.h>
// Условие:
//
// Написать логическую рекурсивную функцию и используя ее определить является ли
// введенное натуральное число точной степенью двойки.
// Входные данные: Одно натуральное число.
// Выход: YES или NO

int is2pow(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    if (userNumber == 0)
    {
        printf("NO\n");
        return 0;
    }
    is2pow(userNumber) ? printf("NO\n") : printf("YES\n");
    return 0;
}

int is2pow(int n)
{
    if (n / 2 == 0)
    {
        return 0;
    }
    return n % 2 || is2pow(n / 2);
};