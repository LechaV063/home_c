#include <stdio.h>

// Постановка задачи:
// Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего.
// Гарантируется, что такое число ровно 1.
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Одно число, которое встречается чаще других.

const int LENGTH = 10;               // длина массива
int inputData(int *arr, int n);      // для заполнения массива, возращает индекс последнего элемента
int mostElement(int *inpArr, int n); // выводит самый распрастранённый элемент

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    printf("%d\n", mostElement(inptArray, LENGTH));
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

int mostElement(int *inpArr, int n)
{
    int maxFrequnce = 0;
    int repeat[n];
    for (int i = 0; i < n; i++)
        repeat[i] = 1;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (inpArr[i] == inpArr[j])
            {
                repeat[i]++;
                repeat[j]++;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (repeat[i] > repeat[maxFrequnce])
            maxFrequnce = i;
    }
    return inpArr[maxFrequnce];
};