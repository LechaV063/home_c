#include <stdio.h>

// Сумма цифр четна
// Составить функцию логическую функцию, которая определяет, верно ли,
// что сумма его цифр – четное число. Используя эту функцию решить задачу.

int summDigitsEven(int number);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    summDigitsEven(userNumber) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int summDigitsEven(int number)
{
    int summ = 0;
    while (number > 0)
    {
        summ += number % 10;
        number /= 10;
    }
    return summ % 2 ? 0 : 1; // возращаем 1 если делится на 2 нацело.
}