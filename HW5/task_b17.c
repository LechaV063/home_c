#include <stdio.h>

// Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых
// сумма цифр равна произведению цифр

int main(int argv, char **argc)
{
    int number, currentDigit, sumDigits = 0, multDigits = 0;
    scanf("%d", &number);
    for (int i = 10; i <= number; i++)
    {
        int localCopy = i;
        sumDigits = multDigits = localCopy%10;
        while (localCopy / 10 > 0)
        {
            localCopy /= 10;
            currentDigit = localCopy % 10;
            sumDigits += currentDigit;
            multDigits *= currentDigit;
        }
        if (multDigits == sumDigits)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}