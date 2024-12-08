#include <stdio.h>

// Постановка задачи:
// В файле input.txt считать символьную строку, не более 10 000 символов. 
// Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
// Учитывать только английские буквы. Результат записать в файл output.txt.
//
// Входные данные: Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
// Выходные данные: Два целых числа. Количество строчных букв и количество заглавных букв.

#define MAXLEN 10000

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

int countLeterals(int size, char *line, int *lower, int *upper)
{
    for (size_t i = 0; i < size; i++)
    {
        if (line[i] >= 'a' && line[i] <= 'z'){
            (*lower)++;
        }
        if (line[i] >= 'A' && line[i] <= 'Z'){
            (*upper)++;
        }
    }
    return *upper + *lower;
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    int lowercaseLetter = 0,
        uppercaseLetter = 0;
    char inputLine[MAXLEN] = {0};
    if (fpIn != NULL && fpOut != NULL) // проверка открылись ли файлы
    {
        readLine(fpIn, inputLine);
        int lenLine = length(MAXLEN, inputLine);
        countLeterals(lenLine, inputLine, &lowercaseLetter, &uppercaseLetter);
        fprintf(fpOut, "%d %d", lowercaseLetter, uppercaseLetter);
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
