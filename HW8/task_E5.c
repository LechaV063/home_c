#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и посчитать сумму положительных элементов массива.
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Одно целое число - сумма положительных элементов массива

const int LENGTH = 10;                   // длина массива
int inputData(int *arr, int n);          // для заполнения массива, возращает индекс последнего элемента
int sumPozitivElements(int *arr, int n); // возращает сумму положительных элементов

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    int indexMax1 = 0, indexMax2 = 0;
    inputData(inptArray, LENGTH);
    printf("%d\n", sumPozitivElements(inptArray, LENGTH));
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

int sumPozitivElements(int *arr, int n)
{
    int summ = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            summ += arr[i];
        }
    }
    return summ;
}