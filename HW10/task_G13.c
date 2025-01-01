#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.
// Входные данные: Строка состоящая из символов: a-z, A-Z, 0-9, /
// Выходные данные: Исходная строка с измененным расширением.

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void findFileName(char inpStr[], char fileName[])
{
    int len;
    char *pIndex = inpStr;
    if ((pIndex = strrchr(inpStr, '/')) != NULL)
    {
        pIndex += 1;
    }
    if ((pIndex = strrchr(pIndex, '.')) != NULL)
    {
        *pIndex = 0;
    }
    strcat(inpStr, ".html");
    strcpy(fileName, inpStr);
}

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inpString[MAXLEN] = {0}, outString[MAXLEN] = {0};
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    int count = fscanf(fpIn, "%[^\n]", inpString);
    // printf("%s", inpString);
    findFileName(inpString, outString);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
