#include <stdio.h>
// Условие:
//Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
// Входные данные: Одно натуральное число.
// Выход: Целое число - сумма цифр введенного числа.

int sum_digits(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    printf("%d\n", sum_digits(userNumber));
    return 0;
}

int sum_digits(int n){
    if(n/10 ==0){
        return n%10;
    }
    return n%10+sum_digits(n/10);
};