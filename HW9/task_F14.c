#include <stdio.h>

// Постановка задачи:
// Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
// Входныне данные: Функция принимает концы отрезка from и to, размер массива, массив целых чисел
// Выходные данные: Функция возвращает сумму элементов в интервале [from, to]

int sum_between_ab(int from, int to, int size, int a[]);

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

int sum_between_ab(int from, int to, int size, int a[])
{
    int summ = 0, temp;
    if (from > to) {
        temp = to;
        to = from;
        from =temp;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
        {
            summ += a[i];
        }
    }
    return summ;
};

int main(int argv, char **argc)
{
    int userArray[MAXSIZE], numFrom, numTo;
    scanf("%d %d", &numFrom, &numTo);
    inputData(MAXSIZE, userArray);
    printf("%d\n", sum_between_ab(numFrom, numTo, MAXSIZE, userArray));
    return 0;
}
