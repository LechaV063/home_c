#include <stdio.h>

// Постановка задачи:
// Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
// Входныне данные: Функция принимает на вход размер массива и массив чисел типа int
// Выходные данные: Функция не возвращает значения, измененный массив сохраняется на месте исходного.

#define MAXSIZE 10

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

void change_max_min(int size, int a[])
{
    int min = a[0], max = a[0],
        indexMin = 0, indexMax = 0;
    for (int i = 1; i < size; i++)
    {
        if (a[i] > max)
        {
            indexMax = i;
            max = a[i];
        }
        if (a[i] < min)
        {
            indexMin = i;
            min = a[i];
        }
    }
    a[indexMax] = min;
    a[indexMin] = max;
}

int main(int argv, char **argc)
{
    int userArray[MAXSIZE];
    inputData(MAXSIZE, userArray);
    change_max_min(MAXSIZE, userArray);
    printData(MAXSIZE, userArray);
    return 0;
}
