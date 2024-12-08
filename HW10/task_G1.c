#include <stdio.h>

// Постановка задачи:
// В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
// Входные данные: aab
// Выходные данные: aab, aab, aab 3

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

#define MAXLEN 100

int main(int argv, char **argc)
{
    FILE *fInput, *fOutput;
    signed char ch;
    char inputLine[MAXLEN] = "";
    fInput = fopen(inputFileName, "r");
    fOutput = fopen(outputFileName, "w");
    if (fInput != NULL && fOutput != NULL)
    {
        readLine(fInput, inputLine);
        fprintf(fOutput, "%s, ", inputLine);
        fprintf(fOutput, "%s, ", inputLine);
        fprintf(fOutput, "%s %d", inputLine, length(MAXLEN, inputLine));
    }
    fclose(fOutput);
    fclose(fInput);
    return 0;
}
