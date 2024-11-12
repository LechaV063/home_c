#include <stdio.h>

// Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
// Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …,
// в которой каждое последующее число равно сумме двух предыдущих.

int main(int argv, char **argc)
{
    int num1 = 1, num2 = 1, feb, n;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    if (n == 1)
    {
        printf("1\n");
    }
    else
    {
        printf("1 1 ");
        for (int i = 2; i < n; i++)
        {
            feb = num1 + num2;
            num1 = num2;
            num2 = feb;
            printf("%d ", feb);
        }
        printf("\n");
    }
    return 0;
}