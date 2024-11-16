#include <stdio.h>

//  Составить функцию, которая переводит число N из
// десятичной системы счисления в P-ичную систему счисления.

int convert(int n, int p);

int main(int argv, char **argc)
{
    int number, power;
    scanf("%d %d", &number, &power);
    if (number >= 0 && power >= 2 && power <= 9)
    {
        printf("%d\n", convert(number, power));
    }
    return 0;
}

int convert(int n, int p)
{
    int currentDigit = 0;
    int result = 0;
    int digits = 0;
    int output;
    result = n % p;
    while (n / p > 0)
    {
        n /= p;
        currentDigit = n % p;
        result *= 10; // передвигаем разряд
        result += currentDigit;
        digits++;
    }
    // разворачиваем result в обратном порядке
    output += result % 10;
    while (digits)
    {
        result /= 10;
        output *= 10;
        currentDigit = result % 10;
        output += currentDigit;
        digits--;
    }
    return output;
}
