#include <stdio.h>
#include <stdlib.h>

// Постановка задачи:
// В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
// Вывести массив по возрастанию в файл output.txt.
// Входные данные: Строка из английских букв, цифр и знаков препинания
// Выходные данные: Последовательность целых чисел отсортированная по возрастанию

#define MAXLEN 1000

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int isDigit(char chr)
{
    int result = 0;
    if (chr >= '0' && chr <= '9')
    {
        result = 1;
    }
    return result;
}

int readDigitToArray(FILE *fp, int *arrOut)
{
    char chr = getc(fp);
    int i = 0, currentNumber, prevDigit = 0;
    while (chr != EOF && chr != '\n')
    {
        if (isDigit(chr))
        {
            if (prevDigit)
            {
                arrOut[i] *= 10;
                arrOut[i] += chr - '0';
            }
            else
            {
                arrOut[i] = chr - '0';
            }
            prevDigit = 1;
        }
        else
        {
            if (prevDigit)
            {
                i++;
                prevDigit = 0;
            }
        }
        chr = getc(fp);
    }
    if (prevDigit)
        i++;
    return i;
}

void writeToFile(FILE *fp, int *arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char line[MAXLEN];
    int arrOut[MAXLEN / 2];
    int numbers = 0;
    if (fpIn == NULL || fpOut == NULL) // проверка открылись ли файлы
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    numbers = readDigitToArray(fpIn, arrOut);
    qsort(arrOut, numbers, sizeof(int), compare);
    writeToFile(fpOut, arrOut, numbers);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
