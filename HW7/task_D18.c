#include <stdio.h>
// Условие:
// Написать рекурсивную функцию и используя ее решить задачу.
// Напечатать цифры введенного натурального числа в порядке
// следования(слева направо) через пробел.

//
// Входные данные: Натуральное число
// Выход: Последовательность цифр в слева направо через пробел

void print_digits(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    print_digits(userNumber);
    printf("\n");
    return 0;
}

void print_digits(int n)
{
    if (n / 10 == 0)
    {
        printf("%d", n % 10);
        return;
    }
    print_digits(n / 10);
    printf(" %d", n % 10);
    return;
};