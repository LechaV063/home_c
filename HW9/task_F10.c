#include <stdio.h>

// Постановка задачи:
// Дана строка состоящая из маленьких латинских букв 'a'..'z'.
// В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>
// Входныне данные: Входная строка состоящая из букв 'a'-'z' не превышающая 1000 символов. В конце строки символ '.'
// Выходные данные: Результат состоящий из букв и чисел, без пробелов

#define MAXSIZE 1000
void compressStr(char *src);

int main(int argv, char **argc)
{
    char sourceLatin[MAXSIZE];
    scanf("%[a-z]", sourceLatin);
    compressStr(sourceLatin);
    printf("\n");
    return 0;
}

void compressStr(char *src)
{
    int count = 1, i = 1, changed = 0;
    if (src[0] != 0 && src[0] != '.')
    {
        printf("%c", src[0]);
    }
    else
        return;
    while (src[i] != '.' && src[i] != 0)
    {
        if (src[i] == src[i - 1])
        {
            count++;
            changed = 0;
        }
        else
        {
            printf("%d", count);
            printf("%c", src[i]);
            count = 1;
            changed = 1;
        }
        i++;
    };
    if (!changed || count == 1)
    {
        printf("%d", count);
    }
}