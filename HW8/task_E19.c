#include <stdio.h>

// Постановка задачи:
// Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.
// Входные данные: Одно натуральное число N
// Выходные данные: Цифры через пробел

#define LENGTH 10                // длина массива
void printData(int *arr, int n); // выводит элементы массива через пробел
int numberToDigits(int num, int *outputArr);
int main(int argv, char **argc)
{
    int userNumber;
    int digitsArray[10]; // 10 - количество 10-тичных разрядов в числе 4294967296
    scanf("%d", &userNumber);
    int lenArr = numberToDigits(userNumber, digitsArray);
    printData(digitsArray, lenArr);
    return 0;
}

void printData(int *arr, int n)
{
    int i;
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    putchar('\n');
};

int numberToDigits(int num, int *outputArr)
{
    int currentDigit;
    int index = 0;
    currentDigit = num % 10;
    outputArr[index] = currentDigit;
    while (num / 10 > 0)
    {
        num /= 10;
        currentDigit = num % 10;
        index++;
        outputArr[index] = currentDigit;
    }
    return index + 1;
};
