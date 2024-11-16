#include <stdio.h>

//  Составить функцию, которая переводит число N из 
// десятичной системы счисления в P-ичную систему счисления.

int convert(int n, int p);
int reverse(int n);

int main(int argv, char ** argc) {
    int number,power;
    scanf("%d %d",&number,&power);
    printf("%d\n", reverse(convert(number, power)));

    return 0;
}

int convert(int n, int p) {
    int currentDigit = 0;
    int result = 0;
    result= n%p;
    while (n/p> 0) 
    {
        n /=p;
        currentDigit = n%p;
        result *= 10;   // передвигаем разряд
        result += currentDigit;
    }
    return result ;
}

int reverse(int n) // переворачиваем цифры в числе
{
    int result=0, currentDigit = 0;
    while (n > 0) {
        currentDigit = n%10;
        n /= 10;
        result *= 10;
        result += currentDigit;
    }
    return result;
}