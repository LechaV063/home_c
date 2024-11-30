#include <stdio.h>

// Постановка задачи:
// В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)
// в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу).
// N не превосходит 1000. Последовательность заканчивается числом 0. Определить пропущенное число.
// Входныне данные: Последовательность целых чисел от M до N. M, N не превосходит 1000.
// Выходные данные: Одно целое число

#define MAXSIZE 1000

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
            break;
    }
    return i;
};

void printData(int n, int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};

int findLost(int size, int *arr)
{
    int min = arr[0], max = arr[0], lost;
    for (size_t i = 1; i < size; i++)
    {
        max = (arr[i] > max) ? arr[i] : max;
        min = (arr[i] < min) ? arr[i] : min;
    }
    int element = min;
    int find;
    for (size_t j = min; j < max; j++)
    {
        find = 0;
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == j)
            {
                find = 1;
                break;
            }
        }
        if (!find)
        {
            lost = j;
            break;
        }
    }
    return lost;
}

int main(int argv, char **argc)
{
    int arrNums[MAXSIZE];
    int len = inputData(MAXSIZE, arrNums);
    printf("%d\n", findLost(len, arrNums));
    return 0;
}
