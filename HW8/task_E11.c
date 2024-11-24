#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и отсортировать его по последней цифре.
//
//
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Этот же массив отсортированный по последней цифре

#define LENGTH 10                      // длина массива
int inputData(int *arr, int n);        // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);       // выводит элементы массива через пробел
void sortByLastDigit(int *arr, int n); // сортирует массив по последней цифре элемента

int main(int argv, char **argc)
{
    int userArray[LENGTH];
    inputData(userArray, LENGTH);
    sortByLastDigit(userArray, LENGTH);
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

void sortByLastDigit(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] % 10 > arr[j] % 10)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
};