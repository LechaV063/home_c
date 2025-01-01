#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// Разработать функцию дана строка из маленьких английских букв. Составить из символов палиндром максимальной длинны.
// При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке. Записать ответ в файл output.txt.
// Входные данные: Строка из маленьких английских букв. Не более 1000 символов.
// Выходные данные: Строка из маленьких английских букв.

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

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
