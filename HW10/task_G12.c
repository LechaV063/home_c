#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt дано предложение требуется разобрать его на отдельные слова.
// Напечатать каждое слово на отдельной строке в файл output.txt.
// Входные данные: Одна строка из английских букв и пробелов не более 1000 символов.
// Выходные данные: Каждое слово на отдельной строке

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void printPerLine(FILE *fp, char inpStr[])
{
    int nums;
    char *pIndex = inpStr;
    char tmpString[MAXLEN];
    while ((nums = sscanf(pIndex, "%s", tmpString)) > 0)
    {
        fprintf(fp, "%s\n", tmpString);
        pIndex = strstr(pIndex, tmpString) + strlen(tmpString) + 1; // ставим указатель в конец строки
    }
}

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
    int count = fscanf(fpIn, "%[^\n]", inpString);
    // printf("%s", inpString);
    printPerLine(fpOut, inpString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
