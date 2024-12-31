#include <stdio.h>
#include <stdlib.h>

// Постановка задачи:
// В файле input.txt дано предложение требуется разобрать его на отдельные слова. 
// Напечатать каждое слово на отдельной строке в файл output.txt.
// Входные данные: Одна строка из английских букв и пробелов не более 1000 символов.
// Выходные данные: Каждое слово на отдельной строке

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}

