#include <stdio.h>

// Постановка задачи:
// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
//
//
// Входные данные: 12 целых чисел через пробел
// Выходные данные: 12 целых чисел через пробел

const int LENGTH = 12;                                  // длина массива
int inputData(int *arr, int n);                         // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);                        // выводит элементы массива через пробел
void cycleShiftRight(int *arr, int n);                  // сдвигает массив на 1 шаг вправо
void cycleRightNStepsShift(int *arr, int n, int steps); // выполнет сдвиг steps - раз

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    int nSteps = 4;
    inputData(inptArray, LENGTH);
    cycleRightNStepsShift(inptArray, LENGTH, nSteps);
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

void cycleRightNStepsShift(int *arr, int n, int steps)
{
    for (size_t i = 0; i < steps; i++)
    {
        cycleShiftRight(arr, n);
    }
}