#include <stdio.h>
// Ввести целое число и найти сумму его цифр.
// Одно целое число большее или равное нулю.
int main(int argv, char **argc)
{
    int number, sum = 0, digit; // sum - нужно инициализировать
    scanf("%d", &number);
    if (number >= 0)
    {
        while (number > 0)
        {
            digit = number % 10; // извлекаем младшую цифру
            number /= 10;
            sum += digit;
        }
        printf("%d\n", sum);
        return 0;
    }
    return 1; // ошибка ввода
}