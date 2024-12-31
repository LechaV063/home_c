#include <stdio.h>
#include <stdlib.h>

// Постановка задачи:
// В файле input.txt в одной строке фамилию, имя и отчество. 
// Сформировать файл приветствие output.txt, где останутся имя и фамилия
// Входные данные: Строка состоящая из английских букв и пробелов не более 100 символов. Формат: Фамилия Имя Отчество
// Выходные данные: Строка состоящая из английских букв и пробелов


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

