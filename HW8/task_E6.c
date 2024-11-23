#include <stdio.h>

// Постановка задачи:
// Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.
// Входные данные: 12 целых чисел через пробел
// Выходные данные: Среднее арифметическое в формате "%.2f"

const int LENGTH = 12;
int inputData(int *arr, int n);
float averageOfArray(int *arr, int n);

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    printf("%.2f\n", averageOfArray(inptArray, LENGTH));
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

float averageOfArray(int *arr, int n)
{
    float result = 0;
    for (size_t i = 0; i < n; i++)
    {
        result += arr[i];
    }
    return result / n;
}