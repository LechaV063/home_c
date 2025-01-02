#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Постановка задачи:
// Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет,
// похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
// Если коды двух слов совпадают, то слова, как правило, звучат похоже.
// Вам требуется реализовать этот алгоритм. Он работает так:
//
// Первая буква слова сохраняется.
// В остальной части слова:
// буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные)
// заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
// 1: b, f, p, v
// 2: c, g, j, k, q, s, x, z
// 3: d, t
// 4: l
// 5: m, n
// 6: r
// Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов.
// Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
// Примеры:
// аmmonium → ammnm → a5555 → a5 → a500
// implementation → implmnttn → i51455335 → i514535 → i514
//
// Входные данные: Во входном файле input.txt находится одно непустое слово, записанное строчными латинскими буквами. Длина слова не превосходит 20 символов.
// Выходные данные: Напечатайте четырёхбуквенный код, соответствующий слову в файл output.txt.

#define MAXLEN 21
#define OUTLEN 4

const char inputFileName[] = "input.txt";
const char outputFileName[] = "output.txt";
void stage1(char *inpS, char *outS)
{
    int index = 0;
    outS[index] = inpS[0];
    for (size_t i = 1; i < strlen(inpS); i++)
    {
        if (inpS[i] != 'a' &&
            inpS[i] != 'e' &&
            inpS[i] != 'h' &&
            inpS[i] != 'i' &&
            inpS[i] != 'o' &&
            inpS[i] != 'u' &&
            inpS[i] != 'w' &&
            inpS[i] != 'y')
        {
            index++;
            outS[index] = inpS[i];
        }
    }
};

void stage2(char *inpS, char *outS)
{
    int index = 0;
    outS[index] = inpS[0];
    for (size_t i = 1; i < strlen(inpS); i++)
    {
        if (inpS[i] == 'b' ||
            inpS[i] == 'f' ||
            inpS[i] == 'p' ||
            inpS[i] == 'v')
        {
            index++;
            outS[index] = '0' + 1;
        }
        else if (inpS[i] == 'c' ||
                 inpS[i] == 'g' ||
                 inpS[i] == 'j' ||
                 inpS[i] == 'k' ||
                 inpS[i] == 'q' ||
                 inpS[i] == 's' ||
                 inpS[i] == 'x' ||
                 inpS[i] == 'z')
        {
            index++;
            outS[index] = '0' + 2;
        }
        else if (inpS[i] == 'd' ||
                 inpS[i] == 't')
        {
            index++;
            outS[index] = '0' + 3;
        }
        else if (inpS[i] == 'l')
        {
            index++;
            outS[index] = '0' + 4;
        }
        else if (inpS[i] == 'm' ||
                 inpS[i] == 'n')
        {
            index++;
            outS[index] = '0' + 5;
        }
        else if (inpS[i] == 'r')
        {
            index++;
            outS[index] = '0' + 6;
        }
    }
};

void stage3(char *inpS, char *outS)
{
    int index = 1;
    outS[0] = inpS[0];
    for (size_t i = 1; i < strlen(inpS); i++)
    {
        if (inpS[i] != inpS[i - 1])
        {
            outS[index] = inpS[i];
            index++;
        }
    }
    outS[index] = 0;
};

void stage4(char *inpS, char *outS)
{
    int index = 1;
    int needNulls = 0;
    outS[0] = inpS[0];
    for (size_t i = 1; i < OUTLEN; i++)
    {
        if (inpS[i] == 0)
        {
            needNulls = 1;
        }
        if (needNulls)
        {
            outS[index] = '0';
            index++;
        }
        else
        {
            outS[index] = inpS[i];
            index++;
        }
    }
    outS[index] = 0;
};

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inpString[MAXLEN] = {0}, outString[MAXLEN] = {0};
    if (fpIn == NULL || fpOut == NULL) // проверка на ошибку открытия файлов
    {
        printf("Файл %s не найден! Аварийный выход из программы.\n", inputFileName);
        exit(1);
    }
    int i = 0;
    int ch;
    while ((ch = getc(fpIn)) != EOF && i < MAXLEN && ch != '\n')
    {
        inpString[i] += ch;
        i++;
    }
    // printf("%s\n", inpString);
    stage1(inpString, outString);
    strcpy(inpString, outString);
    // printf("%s\n", inpString);
    stage2(inpString, outString);
    strcpy(inpString, outString);
    // printf("%s\n", inpString);
    stage3(inpString, outString);
    strcpy(inpString, outString);
    // printf("%s\n", inpString);
    stage4(inpString, outString);
    strcpy(inpString, outString);
    // printf("%s\n", inpString);
    fprintf(fpOut, "%s", outString);
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
