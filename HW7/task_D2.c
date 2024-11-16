#include <stdio.h>
// Условие:
// Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N
//
// Входные данные: Одно натуральное число
// Выход: Сумма чисел от 1 до введенного числа

int recursiveSumm (int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    printf("%d\n", recursiveSumm(userNumber));
    return 0;
}
int recursiveSumm (int n){
    if(n<1) return 0;
    return n+recursiveSumm(n-1);
}
