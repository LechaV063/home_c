#include <stdio.h>

// Постановка задачи:
// В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
// Найдите только те символы слов, которые встречаются в обоих словах только один раз.
// Напечатайте их через пробел в файл output.txt в лексикографическом порядке.
// Входные данные: Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
// Выходные данные: Маленькие английские буквы через пробел.

#define MAXLEN 100

const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";

int lenght(int size, char *str) // возвращает длину строки
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

int isUnique(int size, char *testStr, char character, int indx) // возращает 1 если символ character не повторятся в строке testStr
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

int getUniqueStr(int size, char *Str, char *uniqStr) // возвращает длину строки uniqStr с уникальными символами
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

void sortStr(int size, char *str) // сортирует строку лексикографически
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

        lenWord1 = lenght(MAXLEN, word1); // определение длины слова 1
        lenWord2 = lenght(MAXLEN, word2); // определение длины слова 2

        lenWord1 = getUniqueStr(lenWord1, word1, uniqueFromWord1); // получение уникальных слов
        lenWord2 = getUniqueStr(lenWord2, word2, uniqueFromWord2); // из исходных

        int index = 0;
        for (size_t i = 0; i < lenWord1; i++) // получение результирующей строки
        {
            if (!isUnique(lenWord2, uniqueFromWord2, uniqueFromWord1[i], -1))
            {
                result[index] = uniqueFromWord1[i];
                index++;
            }
        }
        if (index) // если есть результат выводим его в файл output.txt
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
