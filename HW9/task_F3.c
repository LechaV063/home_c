#include <stdio.h>

// Постановка задачи:
// Написать функцию и программу демонстрирующую работу данной функции.
// Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр.
// Цифра пробел сколько раз данная цифра встречается в числе.
// Входныне данные: Натуральное число не более 1000 цифр
// Выходные данные: Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.

void printArray(int arr[], int size);
void digitFrequnce(int arr[], int size, char inpNumber[]);

#define DIGITS 10

int main(int argv, char **argc)
{
    int digits[DIGITS] = {0};
    char userNumber[1000];
    int size;
    scanf("%s", userNumber);
    digitFrequnce(digits, DIGITS, userNumber);
    printArray(digits, DIGITS);
    return 0;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i])
        {
            printf("%d %d\n", i, arr[i]);
        }
    }
}

void digitFrequnce(int arr[], int size, char inpNumber[])
{
    int currentDigit;
    for (int i = 0; inpNumber[i]; i++)
    {
        currentDigit = inpNumber[i] - 0x30;
        arr[currentDigit]++;
    }
};