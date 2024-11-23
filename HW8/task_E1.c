#include <stdio.h>

// Постановка задачи:
// Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.
// Входные данные: 5 целых не нулевых чисел через пробел
// Выходные данные: Одно число в формате "%.3f"

const int LENGTH = 5;
int inputData(int *arr, int n); // для заполнения массива, возращает индекс последнего элемента
float averageOfArray(int *arr, int n);  // возвращает серднее значение элементов массива arr

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    printf("%.3f\n", averageOfArray(inptArray, LENGTH));
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