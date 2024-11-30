#include <stdio.h>

// Постановка задачи:
// Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу:
// например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4]
// (т.к. начинается с нуля, то сразу записывается количество элементов первой серии);
// а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7]
// (т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).
// Входныне данные: Функция принимает исходный массив a[] и сжимает в массив b[], N - число элементов в массиве a[].
// Выходные данные: Функция возвращает число элементов сжатого массива b[]

int compression(int a[], int b[], int N)
{
    int currentBit = 0;
    int count = 0, j = 0;
    for (int i = 0; i < N; i++)
    {
        if (currentBit == a[i])
        {
            count++;
            b[j]=count;
        }
        else
        {
            b[j] = count;
            j++;
            count = 1;
            b[j]=count;
            currentBit = a[i];
        }
    }
    return j+1;
}

// int inputData(int n, int *arr)
// {
//     int i;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &arr[i]);
//     }
//     return i;
// };

// void printData(int n, int *arr)
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

// #define NUMS 100

// int main(int argv, char **argc)
// {
//     int size, i = 0, arrA[NUMS], arrB[NUMS], len;
//     inputData(NUMS, arrA);
//     len = compression(arrA, arrB, NUMS);
//     printData(len, arrB);
//     return 0;
// }
