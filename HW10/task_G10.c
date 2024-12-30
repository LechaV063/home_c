#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt дана строка слов, разделенных пробелами. Найти самое длинное слово и
// вывести его в файл output.txt. Случай, когда самых длинных слов может быть несколько, не обрабатывать.
// Входные данные: Строка из английских букв и пробелов. Не более 1000 символов.
// Выходные данные: Одно слово из английских букв.

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void findLongWord(char *inpString, char *outString)
{
    int maxLength = 0;
    char tmpString[MAXLEN] = {0};
    int index = 0, nums;
    char *pIndex = inpString;
    while ((nums = sscanf(pIndex, "%s", tmpString)) > 0)
    {
        if (strlen(tmpString) > maxLength)
        {
            strcpy(outString, tmpString);
            maxLength = strlen(tmpString);
        }
        pIndex = strstr(pIndex, tmpString) + strlen(tmpString) + 1; // ставим указатель в конец строки
    }
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
    int count = fscanf(fpIn, "%[^\n]", inpString);
    printf("%s", inpString);
    findLongWord(inpString, outString);
    fprintf(fpOut, "%s\n", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
