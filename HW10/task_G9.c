#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.
// Входные данные: Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.
// Выходные данные: Строка из меленьких и больших английских букв.

#define MAXLEN 1000
const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

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

int isUniqe(char chr, char *outString)
{
    int result = 1;
    for (size_t i = 0; i < MAXLEN; i++)
    {
        if (outString[i] && outString[i] == chr)
        {
            result = 0;
            break;
        }
    }
    return result;
}

int filter(char *inpString, char *outString)
{
    int counter = 0;
    char chr;
    for (size_t i = 0; i < MAXLEN; i++)
    {
        chr = inpString[i];
        if (chr && ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z')))
        {
            if (isUniqe(chr, outString))
            {
                outString[counter] = chr;
                counter++;
            }
        }
    }
    return counter;
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inpString[MAXLEN] = {0}, outString[MAXLEN] = {0};
    int len = 0;
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    len = readLine(fpIn, inpString);
    printf("%s\n", inpString);
    filter(inpString, outString);
    writeLine(fpOut, outString, 0);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
