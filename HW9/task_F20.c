#include <stdio.h>

// Постановка задачи:
// Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел.
// Если количество чётных чисел больше, чем количество нечётных, заменить каждое
// нечетное число на произведение нечетных цифр в его десятичной записи.
// Если количество нечётных чисел больше или равно количеству чётных,
// заменить каждое чётное число на произведение чётных цифр в его десятичной записи.
// Входныне данные: 10 целых чисел через пробел
// Выходные данные: 10 целых чисел через пробел

int inputData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

void printData(int size, int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};

int evenGreatThenOdd(int size, int *arr)
{
    int odd = 0, even = 0;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] % 2 == 0 ? even++ : odd++;
    }
    return even > odd ? 1 : 0;
}

int prodEvenDigit(int number)
{
    int result = 1, digit = number % 10;
    if (digit % 2 == 0)
    {
        result *= digit;
    }
    while (number / 10 != 0)
    {
        number /= 10;
        digit = number % 10;
        if (digit % 2 == 0)
        {
            result *= digit;
        }
    };
    return result;
}

int prodOddDigit(int number)
{
    int result = 1, digit = number % 10;
    if (digit % 2 != 0)
    {
        result *= digit;
    }
    while (number / 10 != 0)
    {
        number /= 10;
        digit = number % 10;
        if (digit % 2 != 0)
        {
            result *= digit;
        }
    };
    return result;
}

int main(int argv, char **argc)
{
    const int count = 10;
    int userArr[count];
    inputData(count, userArr);
    if (evenGreatThenOdd(count, userArr))
    {
        for (size_t i = 0; i < count; i++)
        {
            if (userArr[i] % 2 != 0)
            {
                userArr[i] = prodOddDigit(userArr[i]);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < count; i++)
        {
            if (userArr[i] % 2 == 0)
            {
                userArr[i] = prodEvenDigit(userArr[i]);
            }
        }
    }
    printData(count, userArr);
    return 0;
}
