#include <stdio.h>

// Постановка задачи:
// Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
// Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения
// Входныне данные: Функция принимает значения концов отрезка from и to, размер массива, массив целых чисел.
// Выходные данные: Функция возвращает целое число - количество чисел в интервале [from, to]

int count_between(int from, int to, int size, int a[]);

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

int count_between(int from, int to, int size, int a[])
{
    int count=0;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i]>=from && a[i]<=to) {
            count++;
        }
    }
    
    return count;
};

int main(int argv, char **argc)
{
    int userArray[MAXSIZE], numFrom, numTo;
    scanf("%d %d", &numFrom, &numTo);
    inputData(MAXSIZE, userArray);
    printf("%d\n", count_between(numFrom, numTo, MAXSIZE, userArray));
    return 0;
}
