#include <stdio.h>

// Постановка задачи:
// Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
// Входные данные: 5 целых чисел через пробел
// Выходные данные: Одно единственное целое число

const int LENGTH = 5;
int inputData(int *arr, int n); // для заполнения массива, возращает индекс последнего элемента
int minOfArray(int *arr, int n); // возвращает минимум из массива arr

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    printf("%d\n", minOfArray(inptArray, LENGTH));
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

int minOfArray(int *arr, int n)
{
    int minimum = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        minimum = arr[i]<minimum?arr[i]:minimum;
    }
    return minimum;
}