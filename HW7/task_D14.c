#include <stdio.h>
// Условие:
// Дана последовательность целых чисел через пробел, завершающаяся числом 0.
// Выведите все нечетные числа из этой последовательности, сохраняя их порядок.
// Составить рекурсивную функцию.
// Входные данные: Последовательность не нулевых целых чисел. В конце число 0.
// Выход: Введенная последовательность, кроме четных чисел в том же порядке. Число 0 не выводить.

void printOdd(void);

int main(int argv, char **argc)
{
    printOdd();
    printf("\n");
    return 0;
}

void printOdd(void)
{
    int num;
    scanf("%d", &num);
    if (num == 0)
    {
        return;
    }
    if (num % 2 != 0)
    {
        printf("%d ", num);
    }
    printOdd();
    return;
};