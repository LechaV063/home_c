#include <stdio.h>
// Условие:
// Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. Составить рекурсивную функцию.
// Входные данные: Натуральное число
// Выход: Целое число - количество единиц в двоичной записи числа.

int numberBinary1(int num);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    printf("%d\n", numberBinary1(userNumber));
    return 0;
}

int numberBinary1(int num) {
    if (num/2 ==0){
        return num%2;
    }
    return num%2 + numberBinary1(num/2);
};