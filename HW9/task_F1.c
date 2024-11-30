#include <stdio.h>

// Постановка задачи:
// Написать только одну функцию, которая сортирует массив по возрастанию.
//
// Входныне данные: Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
// Выходные данные: Функция ничего не возвращает. Производит сортировку переданного ей массива по возрастанию.

void sort_array(int size, int a[]);
// int inputData(int *arr, int n);
// void printData(int *arr, int n);

// int main(int argv, char **argc)
// {
//     int size = 5;
//     int userArray[size];
//     inputData(userArray, size);
//     sort_array(size, userArray);
//     printData(userArray, size);
//     return 0;
// }

// int inputData(int *arr, int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     return i;
// };

// void printData(int *arr, int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         printf("%d", arr[i]);
//         if (i != n - 1) // после последнего элемента пробел не пишим
//         {
//             putchar(' ');
//         }
//     }
//     putchar('\n');
// };

void sort_array(int size, int a[])
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
};
