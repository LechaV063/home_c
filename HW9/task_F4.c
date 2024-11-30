#include <stdio.h>

// Постановка задачи:
// Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры,
// входящие в строку. Цифра - количество.
// Входныне данные: Строка из английских букв, пробелов, знаков препинания и цифр
// Выходные данные: Функция должна принмать на вход строку и выводить на печать по формату: Цифра пробел количество.

void print_digit(char s[]);

int main(int argv, char **argc)
{
    char inputStr[100];
    int i = 0;
    char c;
    c = getchar();
    while (c != '\n')
    {
        inputStr[i] = c;
        c = getchar();
        i++;
    };
    print_digit(inputStr);
    return 0;
}

void print_digit(char s[])
{
    int digits[10] = {0};
    int smbl;
    while (*s)
    {
        smbl = *s - 0x30;
        if (smbl >= 0 && smbl <= 9)
        {
            digits[smbl]++;
        }
        s++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (digits[i])
        {
            printf("%d %d\n", i, digits[i]);
        }
    }
};