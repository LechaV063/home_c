#include <stdio.h>

// Постановка задачи:
// Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
// Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует. Если отрицательных элементов нет - массив не менять.
// Входныне данные: Функция принимает на вход размер массива и указатель на начало массива. Массив состоит из целых чисел
// Выходные данные:

#define MAXSIZE 10

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] == 0)
            break;
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

void swap_negmax_last(int size, int a[])
{
    int index = 0, temp = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            if (temp)
            {
                if (a[i] > temp)
                {
                    temp = a[i];
                    index = i;
                }
            }
            else
            {
                temp = a[i];
                index = i;
            }
        }
    }
    if (temp && index != size - 1)
    {
        a[index] = a[size - 1];
        a[size - 1] = temp;
    }
};

int main(int argv, char **argc)
{
    int userArr[MAXSIZE];
    inputData(MAXSIZE, userArr);
    swap_negmax_last(MAXSIZE, userArr);
    printData(MAXSIZE, userArr);
    return 0;
}
