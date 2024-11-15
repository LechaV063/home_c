#include <stdio.h>

// Дан текст состоящий из английских букв и цифр, заканчивается символом «.»
// Перевести все заглавные английские буквы в строчные.

int main(int argv, char **argc)
{
    char character = '\0';
    while (1)
    {
        scanf("%c", &character); // считываем посимвольно
        if (character == '.')
            break;
        if (character >= 'A' && character <= 'Z') // символ заглавная латинская буква
        {
            character += 'a' - 'A'; // в верхий регистр
        }
        printf("%c", character);
    }
    printf("\n");
    return 0;
}