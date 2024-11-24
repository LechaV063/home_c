#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.
//
//
// Входные данные: 10 целых чисел через пробел
// Выходные данные: 10 целых чисел через пробел сдвинутых вправо на 1 элемент циклически

const int LENGTH = 10;                 // длина массива
int inputData(int *arr, int n);        // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);       // выводит элементы массива через пробел
void cycleShiftRight(int *arr, int n); // сдвигает массив на 1 шаг вправо

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    cycleShiftRight(inptArray, LENGTH);
    printData(inptArray, LENGTH);
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

void printData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};

void cycleShiftRight(int *arr, int n)
{
    int temp = arr[n - 1];
    for (size_t i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}