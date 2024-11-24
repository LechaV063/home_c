#include <stdio.h>

// Постановка задачи:
// Дан массив из 10 элементов. В массиве найти элементы,
// которые в нем встречаются только один раз, и вывести их на экран.
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Элементы которые встречаются только один раз через пробел

#define LENGTH 10                                 // длина массива
int inputData(int *arr, int n);                   // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);                  // выводит элементы массива через пробел
int uniqueArray(int *inpArr, int n, int *unique); // возвращает длину массива уникальных значений

int main(int argv, char **argc)
{
    int inptArray[LENGTH], uniqueArr[LENGTH];
    int numberUniqueValues;
    inputData(inptArray, LENGTH);
    numberUniqueValues = uniqueArray(inptArray, LENGTH, uniqueArr);
    printData(uniqueArr, numberUniqueValues);
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

int uniqueArray(int *inpArr, int n, int *unique)
{
    int frequence[n];
    for (size_t i = 0; i < n; i++) // зануляем количество повторений элементов до сканирования
    {
        frequence[i] = 0;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (inpArr[i] == inpArr[j])
            {
                frequence[j] = 1; // помечаем пару как не уникальную
                frequence[i] = 1; // помечаем пару как не уникальную
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (!frequence[i])
        {
            unique[index] = inpArr[i];
            index++;
        }
    }
    return index;
};