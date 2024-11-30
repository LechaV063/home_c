#include <stdio.h>

// Постановка задачи:
// Написать только одну функцию, которая находит максимальный элемент в массиве. Всю программу загружать не надо.
// Прототип функции: int find_max_array(int size, int a[])
// Входныне данные: Массив состоящий из целых чисел. Первый аргумент, размер массива, второй аргумент адрес нулевого элемента.
// Выходные данные: Одно целое число

int find_max_array(int size, int a[]);

// int inputData(int *arr, int n);
// int main(int argv, char **argc)
// #define NUMS 98
// {
//     int size, i = 0, arr[NUMS], num;
//     inputData(arr, NUMS);
//     printf("%d\n", find_max_array(NUMS, arr));
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

int find_max_array(int size, int a[])
{
    int maximum = *a;
    for (int i = 1; i < size; i++)
    {
        a++;
        maximum = (*a > maximum) ? *a : maximum;
    }
    return maximum;
};