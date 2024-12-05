#include <stdio.h>

// Постановка задачи:
// Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм вычисления
// суммы максимальных элементов из каждой строки. Напечатать значение этой суммы.
// Предполагается, что в каждой строке такой элемент единственный.
// Реализовать функцию поиска максимума в строке из 10 элементов
// Входныне данные: 10 строк состоящих из 10 целых чисел через пробел.
// Выходные данные: Одно целое число

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

void printData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};
int MaxRowItem(int size, int *arr)
{
    int max = *arr;
    for (size_t i = 1; i < size; i++)
    {
        max = *(arr + i) > max ? *(arr + i) : max;
    }
    return max;
};

int main(int argv, char **argc)
{
    const int count = 10;
    int matrix[count][count];
    for (size_t i = 0; i < count; i++)
    {
        inputData(count, matrix[i]);
    }
    int summ = 0;
    for (size_t i = 0; i < count; i++)
    {
        summ += MaxRowItem(count, matrix[i]);
    }
    printf("%d\n", summ);
    return 0;
}
