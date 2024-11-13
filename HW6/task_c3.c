#include <stdio.h>

// Написать функцию, которая возвращает среднее арифметическое
// двух переданных ей аргументов (параметров).

int middle(int a, int b);

int main(int argv, char **argc)
{
    int number1, number2;
    scanf("%d %d", &number1, &number2);
    printf("%d\n", middle(number1, number2));
    return 0;
}

int middle(int a, int b)
{
    if ((a + b) % 2 == 1)
    {
        return (a + b + 1) / 2;
    }
    else
    {
        return (a + b) / 2;
    }
};