#include <stdio.h>
// Посчитать количество четных и нечетных цифр числа.
// Одно целое неотрицательное число.
int main(int argv, char **argc)
{
    int userNumber, currentDigit, odd = 0, even = 0; // odd - нечётный, even - чётный
    scanf("%d", &userNumber);
    if (userNumber >= 0)
    {
        currentDigit = userNumber % 10;
        currentDigit % 2 == 0 ? even++ : odd++; // младший разряд чётный ?
        while (userNumber / 10 > 0)
        {
            userNumber /= 10;
            currentDigit = userNumber % 10;
            currentDigit % 2 == 0 ? even++ : odd++; // текущий разряд чётный ?
        }
        printf("%d %d\n", even, odd);
        return 0;
    }
    return 1; // error number is negative
}
