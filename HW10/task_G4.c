#include <stdio.h>

// Постановка задачи:
//
//
// Входныне данные:
// Выходные данные:

#define MAXLEN 100

const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";

int lenght(int size, char *str)
{
    int result = 0;
    for (int i = 0; i < size; i++)
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

int isUnique(int size, char *testStr, char character, int indx)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i == indx)
        {
            continue;
        }
        else if (testStr[i] == character)
        {
            return 0; // символ в слове не уникален
        }
    }
    return 1; // символ в слове уникален
}

int getUniqueStr(int size, char *Str, char *uniqStr)
{
    int index = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (isUnique(size, Str, Str[i], i))
        {
            uniqStr[index] = Str[i];
            index++;
        }
    }
    return index;
}

void sortStr(int size, char *str)
{
    char temp;
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main(int argv, char **argc)
{
    FILE *fpIn,
        *fpOut;
    char word1[MAXLEN], word2[MAXLEN],                                // строки с исходными словами
        uniqueFromWord1[MAXLEN] = {0}, uniqueFromWord2[MAXLEN] = {0}, // слова с уникальными буквами
        result[MAXLEN] = {0};                                         // результирующая строка
    int lenWord1, lenWord2;                                           // длины слов
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    if (fpIn != NULL && fpOut != NULL) // проверка открылись ли файлы
    {
        fscanf(fpIn, "%[a-z] %[a-z]", word1, word2); // получение слов из файла input.txt
        lenWord1 = lenght(MAXLEN, word1);            // определение длины слова 1
        lenWord2 = lenght(MAXLEN, word2);            // определение длины слова 2
        lenWord1 = getUniqueStr(lenWord1, word1, uniqueFromWord1);
        lenWord2 = getUniqueStr(lenWord2, word2, uniqueFromWord2);
        int index = 0;
        for (size_t i = 0; i < lenWord1; i++)
        {
            if (!isUnique(lenWord2, uniqueFromWord2, uniqueFromWord1[i], -1))
            {
                result[index] = uniqueFromWord1[i];
                index++;
            }
        }
        if (index)
        {
            sortStr(lenght(MAXLEN, result), result);
            int i = 0;
            while (result[i])
            {
                fprintf(fpOut, "%c ", result[i]);
                i++;
            }
        }
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
