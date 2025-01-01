#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// Считать предложение из файла input.txt и определить можно ли из английских букв предложения
// записанного в файле получить одно слово - палиндром. Ответ напечатать на стандартный поток вывода.
// Требуется реализовать логическую функцию и применить ее.
// Входные данные: Строка из маленьких английских букв и пробелов. Не более 1000 символов.
// Выходные данные: YES или NO

#define MAXLEN 1000
#define NUMBLETTERS 26
typedef struct
{
    char symbol;
    int freq;
} letter;

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

int is_palindrom(char *inpS)
{
    letter arrLetters[NUMBLETTERS];
    int result = 0;
    int indxLetter;
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
            result = 1;
            arrLetters[i].freq -= 2; // убираем пару
        }
    }
    if (!result)
    {
        return 0; // нет ни одной повторяющейся буквы
    }
    else
    {
        result = 0;
    }
    for (size_t i = 0; i < NUMBLETTERS; i++)
    {
        if (arrLetters[i].freq >= 1)
        {
            result++; // подсчёт непарных букв
        }
    }
    if (result > 1)
        return 0;
    else
        return 1;
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inpString[MAXLEN] = {0};
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    fscanf(fpIn, "%[^\n]", inpString);
    is_palindrom(inpString) ? printf("YES\n") : printf("NO\n");
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
