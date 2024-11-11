#include <stdio.h>

// Дана последовательность ненулевых целых чисел,
// в конце последовательности число 0. Посчитать количество чисел.

int main(int argv, char **argc)
{
    int number, count = 0;
    while (1)
    {
        scanf("%d", &number);
        if (number == 0) { 
            break; // выход по нулевому числу из цикла опроса ввода
        };
        count++;
    }
    printf("%d\n", count);
    return 0;
}