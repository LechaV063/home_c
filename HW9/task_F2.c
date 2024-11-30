#include <stdio.h>

// Постановка задачи:
// Написать только одну функцию, которая ставит в начало массива все четные элементы,
// а в конец – все нечетные. Не нарушайте порядок следования чисел между собой.
// Входныне данные: Функцийя принмате на вход целые числа
// Выходные данные: Отсортированный исходный массив

void sort_even_odd(int n, int a[]);
// int inputData(int *arr, int n);
// void printData(int *arr, int n);

// int main(int argv, char **argc)
// {
//     int size = 20;
//     int userArray[size];
//     inputData(userArray, size);
//     sort_even_odd(size, userArray);
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
// }

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
// }

void sort_even_odd(int n, int a[])
{
    int temp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
        {
            {
                if (a[j] % 2 && !(a[j + 1] % 2))
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
}
