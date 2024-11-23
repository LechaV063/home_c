#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
//
//
// Входные данные: 10 целых чисел через пробел.
// Выходные данные: Сумма двух максимальных элементов.

const int LENGTH = 10;                                  // длина массива
int inputData(int *arr, int n);                         // для заполнения массива, возращает индекс последнего элемента
int indexOfMaximum(int *arr, int n, int *excludeIndex); // ищет индекс максимума, исключает из поиска excludeIndex

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    int indexMax1 = 0, indexMax2 = 0;
    inputData(inptArray, LENGTH);
    indexMax1 = indexOfMaximum(inptArray, LENGTH, &indexMax1);
    indexMax2 = indexOfMaximum(inptArray, LENGTH, &indexMax1);
    printf("%d\n", inptArray[indexMax1] + inptArray[indexMax2]);
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

int indexOfMaximum(int *arr, int n, int *excludeIndex)
{
    int currentMax, indexMax; // максимум массива и его индекс
    if (*excludeIndex)
    {
        indexMax = 0;
        currentMax = arr[indexMax];
    }
    else
    {
        indexMax = 1;
        currentMax = arr[indexMax];
    }
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > currentMax && i != *excludeIndex)
        {
            currentMax = arr[i];
            indexMax = i;
        }
    }
    return indexMax;
};