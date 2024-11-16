#include <stdio.h>
// Условие:
// Составить рекурсивную функцию, печать всех чисел от 1 до N
//
// Входные данные: Одно натуральное число

// Выход: Последовательность чисел от 1 до введенного числа

void recursive_print(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    recursive_print(userNumber);
    printf("\n");
    return 0;
}

void recursive_print(int n){
    if (n<1){
        return;
    }
    recursive_print(n-1);
    printf("%d ", n);
}