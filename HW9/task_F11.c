#include <stdio.h>

// Постановка задачи:
// Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int.
// Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.
// Входныне данные: Последовательность из 30 целых чисел через пробел
// Выходные данные: Два целых числа через пробел

#define MAXSIZE 30

int inputData(int n, int *arr)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

void change_max_min(int size, int a[]){
    
}
void indexMinSumm(int size, int *arr)
{
    int summ = arr[0] + arr[1], indx1 = 0, indx2 = 1;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] + arr[j] < summ)
            {
                indx1 = i;
                indx2 = j;
                summ = arr[i] + arr[j];
            }
        }
    }
    printf("%d %d\n", indx1, indx2);
};

int main(int argv, char **argc)
{
    int userArray[MAXSIZE];
    inputData(MAXSIZE, userArray);
    indexMinSumm(MAXSIZE, userArray);
    return 0;
}
