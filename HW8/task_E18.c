#include <stdio.h>

// Постановка задачи:
// В диапазоне натуральных чисел от 2 до N определить,
// сколько из них кратны любому из чисел в диапазоне от 2 до 9.
// Входные данные: Одно целое число N большее 2 и не превосходящее 10000
// Выходные данные: Все числа от 2 до 9 в формате:
// 2 количество чисел кратных 2
// 3 количество чисел кратных 3
// 4 количество чисел кратных 4
// 5 количество чисел кратных 5
// 6 количество чисел кратных 6
// 7 количество чисел кратных 7
// 8 количество чисел кратных 8
// 9 количество чисел кратных 9

void printData(int *arr, int n);                 // форматированный вывод
void multiplyOfArray(int *multiply, int maxNum); // формируют массив кратности

int main(int argv, char **argc)
{
    int userNumber,
        multArr[8] = {0}; // массив кратности для 8-ми цифр
    scanf("%d", &userNumber);
    multiplyOfArray(multArr, userNumber);
    printData(multArr, 8);
    return 0;
}

void printData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", i + 2, arr[i]);
    }
};

void multiplyOfArray(int *multiply, int maxNum)
{
    for (size_t i = 2; i <= maxNum; i++)
    {
        for (int j = 2; j <= 9; j++)
        {
            if (!(i % j))
            {
                multiply[j - 2]++;
            }
        }
    }
};
