#include <stdio.h>
#include <stdlib.h>

// Постановка задачи:
// В файле input.txt дано предложение. Необходимо заменить 
// все имена «Cao» на «Ling» и записать результат в файл output.txt.
// Входные данные: Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.
// Выходные данные: Строка из английский букв, знаков препинания и пробелов.


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

