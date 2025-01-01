#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны.
// При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.
// Входные данные: Строка из маленьких английских букв. Не более 1000 символов.
// Выходные данные: Строка из маленьких английских букв.

#define MAXLEN 1000
#define NUMBLETTERS 26
typedef struct
{
    char symbol;
    int freq;
} letter;

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

void poliandrom(char *inpS, char *outS)
{
    letter arrLetters[NUMBLETTERS];
    int lenOutputWord = 0;
    int indxLetter = 0, indxOutpWord = 0;
    int poliandromPossible = 0;
    int additionLetter = 0;
    for (size_t i = 0; i < NUMBLETTERS; i++)
    {
        arrLetters[i].symbol = 'a' + i;
        arrLetters[i].freq = 0;
    }
    for (size_t i = 0; i < strlen(inpS); i++)
    {
        if (inpS[i] >= 'a' && inpS[i] <= 'z')
        {
            indxLetter = inpS[i] - 'a';
            arrLetters[indxLetter].freq++;
        }
    }
    for (size_t i = 0; i < NUMBLETTERS; i++)
    {
        while (arrLetters[i].freq >= 2)
        {
            outS[indxOutpWord] = arrLetters[i].symbol;
            lenOutputWord++;
            indxOutpWord++;
            arrLetters[i].freq -= 2;
            poliandromPossible = 1;
        }
    }
    lenOutputWord *= 2;
    for (size_t i = 0; i < NUMBLETTERS; i++)
    {
        if (arrLetters[i].freq > 0)
        {
            outS[indxOutpWord] = arrLetters[i].symbol;
            additionLetter = 1;
            break;
        }
    }
    for (size_t i = 0; i < (lenOutputWord + additionLetter - 1) / 2; i++)
    {
        outS[lenOutputWord - i] = outS[i];
    }
    // printf("%s\n", outS);
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
    fscanf(fpIn, "%[^\n]", inpString);
    poliandrom(inpString, outString);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
