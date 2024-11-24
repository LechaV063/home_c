#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.
//
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Исходный массив. Первая часть отсортирована по возрастанию, вторая половина по убыванию.

#define LENGTH 10                    // длина массива
int inputData(int *arr, int n);      // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);     // выводит элементы массива через пробел
void diffSortArray(int *arr, int n); // сортирует первую половину по возрастанию вторую по убиванию

int main(int argv, char **argc)
{
    int userArray[LENGTH];
    inputData(userArray, LENGTH);
    diffSortArray(userArray, LENGTH);
    printData(userArray, LENGTH);
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

void diffSortArray(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i + 1; j < n / 2; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};