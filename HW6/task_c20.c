#include <stdio.h>

// Проверить строку состоящую из скобок "(" и ")" на корректность.

int isBracket(char ch);

int main(int argv, char **argc)
{
    char character;
    int summ = 0;
    character = getchar();
    while (character != '.')
    {
        summ += isBracket(character);
        character = getchar();
        if (summ < 0) // сначала идут открывающие скобки 
        {
            break; 
        }
    }
    summ == 0 ? printf("YES\n") : printf("NO\n");
    return 0;
}

int isBracket(char ch)
{
    if (ch == '(')
        return 1; // открывающая скобка
    if (ch == ')')
        return -1; // закрывающая скобка
    return 0; // символ не скобка
}