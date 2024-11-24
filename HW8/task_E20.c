#include <stdio.h>

// Постановка задачи:
// Переставить цифры в числе так, что бы получилось максимальное число.
// Входные данные: Одно целое не отрицательное число
// Выходные данные: Целое не отрицательное число

int numberToDigits(int num, int *outputArr);   // раскладывает число в массив цифр
int maxPossibleNumber(int *inputArr, int num); // возращает максимальное возможное число из массива цифр

int main(int argv, char **argc)
{
    int userNumber, greatNumber;
    int digitArray[10] = {0}, nums;
    scanf("%d", &userNumber);
    nums = numberToDigits(userNumber, digitArray);
    greatNumber = maxPossibleNumber(digitArray, nums);
    printf("%d\n", greatNumber);
    return 0;
}

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
    int temp;
    for (int i = 0; i < index / 2; i++) // оборачиваем порядок цифр
    {
        temp = outputArr[i];
        outputArr[i] = outputArr[index - i];
        outputArr[index - i] = temp;
    }
    return index + 1;
};

int maxPossibleNumber(int *inputArr, int num)
{
    int temp;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (inputArr[i] < inputArr[j])
            {
                temp = inputArr[i];
                inputArr[i] = inputArr[j];
                inputArr[j] = temp;
            }
        }
    }
    int result = inputArr[0];
    for (int i = 1; i < num; i++)
    {
        result *= 10;
        result += inputArr[i];
    }
    return result;
};