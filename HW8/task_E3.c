#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.
// Входные данные: 10 целых чисел через пробел
// Выходные данные: 4 целых числа через пробел: номер максимума, максимум, номер минимума, минимум.

const int LENGTH = 10;                       // длина массива
int inputData(int *arr, int n);              // для заполнения массива, возращает индекс последнего элемента
int minOfArray(int *arr, int n, int *index); // возвращает минимум из массива arr  *index - указатель на индекс результата
int maxOfArray(int *arr, int n, int *index); // возвращает максимум из массива arr *index - указатель на индекс результата

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    int indexOfMax = 0, indexOfMin = 0; // начальные условия
    int max, min;
    inputData(inptArray, LENGTH);
    min = minOfArray(inptArray, LENGTH, &indexOfMin);
    max = maxOfArray(inptArray, LENGTH, &indexOfMax);
    printf("%d %d %d %d\n", indexOfMax + 1, max, indexOfMin + 1, min);
    return 0;
}

int inputData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

int minOfArray(int *arr, int n, int *index)
{
    int minimum = arr[0];
    *index = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < minimum)
        {
            minimum = arr[i];
            *index = i;
        }
    }
    return minimum;
}

int maxOfArray(int *arr, int n, int *index)
{
    int maximum = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
            *index = i;
        }
    }
    return maximum;
}