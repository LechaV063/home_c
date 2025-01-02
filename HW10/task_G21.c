#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// Cia очень любит равносторонние треугольники. Он все время выкладывает их из камней.
// Ling дал Cia камни и попросил его составить такой треугольник если это возможно. Помогите Cia сложить треугольник используя
// все камни или напечатайте слов NO, если это невозможно. Пример треугольников, которые составляет Cia:
//  *
// * *
//
//   *
//  * *
// * * *
//
//    *
//   * *
//  * * *
// * * * *
//
// Во входном файле input.txt записано некоторое количество символов * (камней).
// Необходимо построить равносторонний треугольник используя все символы * и символ пробел,
// записать ответ в выходной файл output.txt. Между соседними символами * строго один пробел. Если треугольник невозможно составить,
// используя все камни, то необходимо записать единственное слово NO в файл output.txt.
// Входные данные: Текстовый файл состоит из различных символов и символов *.
// Выходные данные: Равносторонний треугольник составленный из символов *, символов пробела и символов переноса строк или слово NO.

#define MAXLEN 10000
#define MAXNUMARRAY 42
const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";

typedef struct
{
    int numStar;
    int starInLine;
    char line[MAXNUMARRAY * 2];
} triangle;

void initArrStar(triangle arr[])
{
    arr[0].numStar = 1;
    arr[0].starInLine = 1;
    for (size_t i = 1; i < MAXNUMARRAY; i++)
    {
        arr[i].numStar = arr[i - 1].numStar + i + 1;
        arr[i].starInLine = arr[i].numStar - arr[i - 1].numStar;
    }
}

int isPossibleDraw(triangle arr[], int numberStars)
{
    int result = 0;
    for (size_t i = 1; i <= MAXNUMARRAY; i++)
    {
        if (arr[i].numStar == numberStars)
        {
            result = arr[i].starInLine;
            break;
        }
    }
    return result;
}

int countStars(char *inpS)
{
    int count = 0;
    for (size_t i = 0; i < strlen(inpS); i++)
    {
        if (inpS[i] == '*')
        {
            count++;
        }
    }
    return count;
}

void drawTriangle(FILE *fp, triangle arr[], int indx)
{
    // fprintf(fp, "YES\n");
    for (size_t i = 0; i < indx; i++)
    {
        for (size_t j = 0; j < indx - arr[i].starInLine; j++)
        {
            fprintf(fp, " ");
        }
        for (size_t k = 0; k < arr[i].starInLine; k++)
        {
            fprintf(fp, "*");
            if (k != arr[i].starInLine - 1)
            {
                fprintf(fp, " ");
            }
        }
        fprintf(fp, "\n");
    }
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    triangle arr[MAXNUMARRAY + 1]; // количество звездочек для рисунка треугольника
    char inpString[MAXLEN] = {0}, outString[MAXLEN] = {0};
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    int i = 0;
    char ch;
    while ((ch = getc(fpIn)) != EOF && i < MAXLEN)
    {
        inpString[i] += ch;
        i++;
    }
    // printf("%s", inpString);
    initArrStar(arr);
    int numberStars = countStars(inpString);
    int indexArr = isPossibleDraw(arr, numberStars);
    if (indexArr)
    {
        // printf("YES\n");
        drawTriangle(fpOut, arr, indexArr);
    }
    else
    {
        // printf("NO\n");
        fprintf(fpOut, "NO\n");
    };
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
