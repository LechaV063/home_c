#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// В файле input.txt записаны символы. Необходимо разработать функцию, которая
// меняет местами пары соседних символов не обращая внимание на символы пробел.
// Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл output.txt.
// Входные данные: Строка из английских букв, пробелов и знаков препинания. Не более 1000 символов.
// Выходные данные: Строка из английских букв, пробелов и знаков препинания.

#define MAXLEN 1001

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void swap(char *str, int nFirst, int nSecond)
{
    char ch;
    ch = str[nFirst];
    str[nFirst] = str[nSecond];
    str[nSecond] = ch;
}

void swapNeigthbor(char *inpS, char *outS)
{
    int size = strlen(inpS);
    int frst = 0, scnd = 1;
    for (size_t i = 0; i < size - 1; i += 2)
    {
        while (inpS[i] == ' ')
        {
            i++;
        }
        frst = i;
        while (inpS[i + 1] == ' ')
        {
            i++;
        }
        scnd = i + 1;
        if (scnd < size)
        {
            swap(inpS, frst, scnd);
        }
    }
    strcpy(outS, inpS);
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
    swapNeigthbor(inpString, outString);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
