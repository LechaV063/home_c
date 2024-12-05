#include <stdio.h>

// Постановка задачи:
// Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел,
// сколько элементов превосходят по модулю максимальный элемент.
// Входныне данные: Функция получает размер массива и массив целых чисел
// Выходные данные: Функция возвращает целое число равное количеству элементов превосходящих по модулю максимальный элемент.

#define MAXSIZE 10

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

int count_bigger_abs(int n, int a[])
{
    int max = a[0], currNumberModule, count = 0;
    for (int i = 1; i < n; i++) // ищем максимум в массиве
    {
        max = *(a + i) > max ? *(a + i) : max;
    }
    max = max > 0 ? max : -max; // модуль максимального значения
    for (int i = 0; i < n; i++)
    {
        currNumberModule = *(a + i) < 0 ? *(a + i) * (-1) : *(a + i); // модуль текущего элемента
        if (currNumberModule > max)
        {
            count++;
        }
    }
    return count;
};

int main(int argv, char **argc)
{
    int userArray[MAXSIZE];
    inputData(MAXSIZE, userArray);
    printf("%d\n", count_bigger_abs(MAXSIZE, userArray));
    return 0;
}
