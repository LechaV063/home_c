#include <stdio.h>

//  Составить логическую функцию, которая определяет, верно ли,
//  что в заданном числе сумма цифр равна произведению.

int is_happy_number(int n);

int main(int argv, char **argc)
{
    int number;
    scanf("%d", &number);
    is_happy_number(number) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int is_happy_number(int n)
{
    int currentDigit, sumDigits = 0, multDigits = 0;
    sumDigits = multDigits = n % 10;
    while (n / 10 > 0)
    {
        n /= 10;
        currentDigit = n % 10;
        sumDigits += currentDigit;
        multDigits *= currentDigit;
    }
    return multDigits == sumDigits ? 1 : 0;
}
