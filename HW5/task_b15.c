#include <stdio.h>

// Дана последовательность ненулевых целых чисел,
// в конце последовательности число 0. Посчитать количество чётных чисел.

int main(int argv, char **argc)
{
    int number, count = 0;
    while (1)
    {
        scanf("%d", &number);
        if (number == 0)
        {
            break; // выход по нулевому числу из цикла опроса ввода
        };
        if (number % 2 == 0)
        {
            count++; // считаем чётные цифры
        }
        else
        {
            continue;
        }
    }
    printf("%d\n", count);
    return 0;
}