#include <stdio.h>
// Условие:
//Составить рекурсивную функцию, печать всех чисел от N до 1.
//
// Входные данные: Одно натуральное число
// Выход: Последовательность целых чисел от введенного числа до 1, через пробел.

void directPrint(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    directPrint(userNumber);
    printf("\n");
    return 0;
}

void directPrint(int n){
    if (n<1){
        return;
    }
    printf("%d ", n);
    directPrint(n-1);
}