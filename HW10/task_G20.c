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

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";
int is_palindrom(string);
int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inpString[MAXLEN], outString[MAXLEN];
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    fscanf(fpIn, "%[^\n]", inpString);
    printf("%s", inpString);

    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
