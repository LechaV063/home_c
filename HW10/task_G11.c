#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Постановка задачи:
// В файле input.txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'.
// Ответ записать в файл output.txt.
// Входные данные: Строка из английских букв и пробелов не более 1000 символов.
// Выходные данные: Одно целое число

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";
int countWordsEndsTo_a(char inpStr[])
{
    int count_end_a = 0, nums = 0;
    char *pIndex = inpStr;
    char tmpString[MAXLEN];
    while ((nums = sscanf(pIndex, "%s", tmpString)) > 0)
    {
        int lastLetter = strlen(tmpString) - 1;
        if (tmpString[lastLetter] == 'a')
        {
            count_end_a++;
        }
        pIndex = strstr(pIndex, tmpString) + strlen(tmpString) + 1; // ставим указатель в конец строки
    }
    return count_end_a;
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
    fprintf(fpOut, "%d\n", countWordsEndsTo_a(inpString));
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
