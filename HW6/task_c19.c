#include <stdio.h>

// Составить функцию, которая преобразует текущий символ цифры в число.
// Написать программу считающую сумму цифр в тексте.

int digit_to_num(char c);

int main(int argv, char **argc)
{
    int summ=0;
    char ch;
    scanf("%c", &ch);
    while (ch!='.')
    {
            summ += digit_to_num(ch);
            scanf("%c", &ch);
    }
    printf("%d\n",summ);

    return 0;
}

int digit_to_num(char c)
{
    return (c >= '0' && c <= '9') ? (c - '0') : 0;
}