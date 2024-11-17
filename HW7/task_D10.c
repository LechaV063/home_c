#include <stdio.h>
// Условие:
// Дано натуральное число n ≥ 1. Проверьте, является ли оно простым.
// Программа должна вывести слово YES, если число простое или NO в противном случае.
// Необходимо составить рекурсивную функцию и использовать ее.
// Входные данные: Натуральное число
// Выход: YES или NO

int is_prime(int n, int delitel);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    is_prime(userNumber, 2) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int is_prime(int n, int delitel)
{
    if (n == 0 || n == 1)
        return 0;
    if (n == delitel)
    {
        return n / delitel;
    }
    return n % delitel && is_prime(n, delitel + 1);
};