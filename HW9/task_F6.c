#include <stdio.h>

// Постановка задачи:
// Написать только одну логическую функцию, которая определяет, верно ли, что среди элементов массива есть два одинаковых.
// Если ответ «да», функция возвращает 1; если ответ «нет», то 0.
// Входныне данные: Массив из целых чисел
// Выходные данные: Функция возвращает 1 или 0

int is_two_same(int size, int a[]);

// int inputData(int n, int *arr);
// int main(int argv, char **argc)
// #define NUMS 10
// {
//     int size, i = 0, arr[NUMS], num;
//     inputData(NUMS, arr);
//     is_two_same(NUMS, arr) ? printf("YES\n") : printf("NO\n");
//     return 0;
// }

// int inputData(int n, int *arr)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     return i;
// };

int is_two_same(int size, int a[])
{
    int result = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                result = 1;
            }
        }
    }
    return result;
};