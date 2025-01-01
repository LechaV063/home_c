#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
// Для решения задачи разработать функцию. Результат записать в output.txt.
// Входные данные: Строка из английских букв, знаков препинания и пробелов. Не более 1000 символов.
// Выходные данные: Строка из английских букв, знаков препинания и пробелов.

#define MAXLEN 1001

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void stripString(char *inpS, char *outS)
{
    int size = strlen(inpS);
    int indexOut = 0;
    for (size_t i = 0; i < size; i++)
    {
        while (i + 1 < size && inpS[i] == ' ' && inpS[i + 1] == ' ')
        {
            i++;
        }
        if (indexOut != 0 || inpS[i] != ' ')
        {
            outS[indexOut] = inpS[i];
            indexOut++;
        }
    }
};

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
    fscanf(fpIn, "%[^\n]", inpString);
    // printf("%s", inpString);
    stripString(inpString, outString);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
