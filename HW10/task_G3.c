#include <stdio.h>

// Постановка задачи:
// В файле input.txt дана строка из 1000 символов. Показать номера символов,
// совпадающих с последним символом строки. Результат записать в файл output.txt
// Входныне данные: Строка не более 1000 символов
// Выходные данные: Целые числа через пробел - номера символа, который совпадает с последним символом строки.

const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";
#define MAXLEN 1000

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    char ch;
    char inputStr[MAXLEN] = {0};
    int i = 0;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    if (fpIn != NULL && fpOut != NULL) // проверка открылись ли файлы
    {
        while ((ch = getc(fpIn)) != EOF && i < MAXLEN && ch != '\n')
        {
            inputStr[i] += ch;
            i++;
        }
    }
    int length = i;
    char target = inputStr[length - 1];
    for (i = 0; i < length - 1; i++)
    {
        if (inputStr[i] == target)
        {
            fprintf(fpOut, "%d ", i);
        }
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
