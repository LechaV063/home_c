#include <stdio.h>

// Постановка задачи:
// В файле input.txt дана символьная строка не более 1000 символов.
// Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные.
// Результат записать в output.txt.
// Входные данные: Строка из маленьких и больших английских букв, знаков препинания и пробелов.
// Выходные данные: Строка из маленьких и больших английских букв, знаков препинания и пробелов.

#define MAXLEN 1000
const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";

int length(int num, char *str)
{
    int result = 0;
    for (int i = 0; i < num; i++)
    {
        if (*str)
        {
            str++;
            result++;
        }
        else
            break;
    }
    return result;
}

int readLine(FILE *f, char *str)
{
    int ch;
    int i = 0;
    ch = getc(f);
    while (ch != EOF && ch != '\n')
    {
        str[i] = ch;
        ch = getc(f);
        i++;
    }
    return i;
}

int writeLine(FILE *f, char *str, char delimeter) // delimeter - символ разделитель
{
    int ch;
    int i = 0;
    while (str[i])
    {
        putc(str[i], f);
        if (delimeter) // если 0 - нет разделителя
            putc(delimeter, f);
        i++;
    }
    return i;
}

void modifyLine(int size, char *line)
{
    char ch;
    for (size_t i = 0; i < size; i++)
    {
        ch = line[i];
        switch (ch)
        {
        case 'a':
            line[i] = 'b';
            break;
        case 'A':
            line[i] = 'B';
            break;
        case 'b':
            line[i] = 'a';
            break;
        case 'B':
            line[i] = 'A';
            break;
        default:
            break;
        }
    }
}

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inputLine[MAXLEN] = {0};
    if (fpIn != NULL && fpOut != NULL) // проверка открылись ли файлы
    {
        readLine(fpIn, inputLine);
        int lenLine = length(MAXLEN, inputLine);
        modifyLine(lenLine, inputLine);
        writeLine(fpOut, inputLine, 0);
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
