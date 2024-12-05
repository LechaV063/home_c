#include <stdio.h>

// Постановка задачи:
// Составить функцию которая находит след матрицы в двумерном массиве.
// Показать пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма элементов на главной диагонали.
// Входныне данные: 25 целых чисел через пробел.
// Выходные данные: Одно целое число.

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

int summDaigonale(int size, int *arr)
{
    int summ = 0;
    for (int i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i == j)
            {
                summ += *(arr + i + size * j);
            }
        }
    }
    return summ;
}

int main(int argv, char **argc)
{
    const int count = 5;
    int  matrix[count][count];
    for (size_t i = 0; i < count; i++)
    {
        inputData(count,  matrix[i]);
    }
    printf("%d\n", summDaigonale(count,  matrix[0]));
    return 0;
}
