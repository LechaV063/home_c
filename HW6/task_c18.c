#include <stdio.h>

/// Составить логическую функцию, которая определяет, что текущий символ это цифра.
// Написать программу считающую количество цифр в тексте.

int is_digit(char c);

int main(int argv, char **argc)
{
    int count=0;
    char ch;
    scanf("%c", &ch);
    while (ch!='.')
    {
        if (is_digit(ch)) {
            count++;
        }
            scanf("%c", &ch);
    }
    printf("%d\n",count);
    return 0;
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0; // возвращаем 1 если символ цифра
}