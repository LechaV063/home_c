#include <stdio.h>

// Постановка задачи:
// Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
//
// Входные данные: 12 целых чисел через пробел
// Выходные данные: 12 целых чисел через пробел

#define LENGTH 12                        // длина массива
#define NUMBERPARTS 3                    // делим массив на три части
int inputData(int *arr, int arrLength);  // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int arrLength); // выводит элементы массива через пробел
void invertArr(int *arr, int arrLength); // инвертирует по раздельности половины исходного массава

int main(int argv, char **argc)
{
    int inptArray[LENGTH];
    inputData(inptArray, LENGTH);
    invertArr(inptArray, LENGTH);
    printData(inptArray, LENGTH);
    return 0;
}

int inputData(int *arr, int arrLength)
{
    int i;
    for (i = 0; i < arrLength; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

void printData(int *arr, int arrLength)
{
    int i;
    for (i = 0; i < arrLength; i++)
    {
        printf("%d", arr[i]);
        if (i != arrLength - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};

void invertArr(int *arr, int arrLength)
{
    int temp;
    int nmbPart = arrLength / NUMBERPARTS; // количество элементов в одной части массива
    for (int part = 0; part < NUMBERPARTS; part++)
    {
        for (int i = nmbPart * part, j = nmbPart * (part + 1) - 1; i < nmbPart * part + nmbPart / 2; i++, j--)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
};
