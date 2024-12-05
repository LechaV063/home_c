#include <stdio.h>

// Постановка задачи:
// Определить количество положительных элементов квадратной матрицы,
// превышающих по величине среднее арифметическое всех элементов главной диагонали.
// Реализовать функцию среднее арифметическое главной диагонали.
// Входныне данные: 5 строк по 5 целых чисел через пробел
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

float midleOfDiagonale(int size, int *arr)
{
    return 1.0 * summDaigonale(size, arr) / size;
}

int main(int argv, char **argc)
{
    const int count = 5;
    int matrix[count][count];
    float midle;
    for (size_t i = 0; i < count; i++)
    {
        inputData(count, matrix[i]);
    }
    midle = midleOfDiagonale(count, matrix[0]);
    int greatThenMidle = 0;
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < count; j++)
        {
            if (matrix[i][j] * 1.0 > midle)
            {
                greatThenMidle++;
            }
        }
    }
    printf("%d\n", greatThenMidle);
    return 0;
}
