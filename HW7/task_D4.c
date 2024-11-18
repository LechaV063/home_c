#include <stdio.h>
// Условие:
// Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке,
//  разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
// Входные данные: Одно целое неотрицательное число
// Выход: Все цифры числа через пробел в прямом порядке.

void directPrint(int num);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    if(userNumber){
    directPrint(userNumber);
    printf("\n");
    }
    else {
        printf("%d\n", userNumber);
    }
    return 0;
}

void directPrint(int num)
{
    if (num == 0)
    {
        return;
    }
    directPrint(num / 10);
    printf("%d ", num%10);
}


