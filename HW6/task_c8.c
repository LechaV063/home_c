#include <stdio.h>

// Составить функцию, которая переводит латинскую строчную букву в заглавную.
// И показать пример ее использования.
// Строка состоящая из английских букв, пробелов и запятых. В конце строки символ точка.

char toUpper(char ch);

int main(int argv, char **argc)
{
    char character;
    while (1)
    {
        scanf("%c", &character);
        if (character == '.')
            break;
        printf("%c", toUpper(character));
    }
    printf("\n");
    return 0;
}

char toUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z') // в диапазоне 0x61 .. 0x7a 
    {
        return ch -= 'a' - 'A'; // вычитаем - 0x20
    }
    return ch;
}
