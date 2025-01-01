#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на «Cao»
// и результат записать в файл output.txt.
// Входные данные: Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
// Выходные данные: Строка из английских букв, пробелов и знаков препинания.

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";
void modifyStr(char *inStr, char *outStr, char *dst, char *src)
{
    char *pTmp, *pInput = inStr;
    int numbers, lenDst = strlen(dst), lenSrc = strlen(src);
    while ((pTmp = strstr(pInput, src)) != NULL)
    {
        numbers = pTmp - pInput;
        strncat(outStr, pInput, numbers);
        strcat(outStr, dst);
        pInput = pTmp + lenSrc;
    };
    strcat(outStr, pInput);
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char srcSubStrng[] = "Ling", dstSubStrng[] = "Cao";
    char inpString[MAXLEN] = {0}, outString[MAXLEN + 250] = {0};
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    fscanf(fpIn, "%[^\n]", inpString);
    // printf("%s", inpString);
    modifyStr(inpString, outString, dstSubStrng, srcSubStrng);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
