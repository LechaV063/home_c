#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и отобрать в другой массив все числа,
// у которых вторая с конца цифра (число десятков) – ноль.
//
// Входные данные: 10 целых чисел через пробел.
// Выходные данные: Целые числа через пробел, у котороых вторая с конца цифра - ноль

const int LENGTH = 10;                                // длина массива
int inputData(int *arr, int n);                       // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);                      // выводит элементы массива через пробел
int makeResultArray(int *inpArr, int *resArr, int n); //

int main(int argv, char **argc)
{
    int inptArray[LENGTH], resultArray[LENGTH];
    int lenResult;
    inputData(inptArray, LENGTH);
    lenResult = makeResultArray(inptArray, resultArray, LENGTH);
    printData(resultArray, lenResult);
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

int makeResultArray(int *inpArr, int *resArr, int n)
{
    int index = 0, digit;
    for (size_t i = 0; i < n; i++)
    {
        if (inpArr[i] / 10 > 0)
        {
            digit = inpArr[i] / 10;
            digit %= 10;
            if (!digit)
            {
                resArr[index] = inpArr[i];
                index++;
            }
        } else {
                resArr[index] = inpArr[i];
                index++;
        }
    }
    return index;
};