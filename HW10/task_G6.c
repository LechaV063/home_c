#include <stdio.h>
#include <stdlib.h>

// Постановка задачи:
// В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, 
// является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
// Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
// Входные данные:
// Строка из заглавных английских букв
// Выходные данные:
// YES или NO

#define MAXLEN 1000
const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";

int length(int num, char *str) // возвращает длину строки
{
    int result = 0;
    for (int i = 0; i < num; i++)
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

int readLine(FILE *f, char *str) // 
{
    int ch;
    int i = 0;
    ch = getc(f);
    while (ch != EOF && ch != '\n') // читаем до конца файла или перевода строки
    {
        str[i] = ch;
        ch = getc(f);
        i++;
    }
    return i;
}

int writeLine(FILE *f, char *str, char delimeter) // delimeter - символ разделитель
{
    int ch;
    int i = 0;
    while (str[i])
    {
        putc(str[i], f);
        if (delimeter) // 0 - нет разделителя
            putc(delimeter, f);
        i++;
    }
    return i;
}

int is_palindrom(char *str){
    int len = length(MAXLEN, str);
    for (size_t i = 0; i < len/2; i++)
    {
        if(str[i]!=str[len-i-1]) 
            {
                return 0;
            }
    }
    
    return 1;
}
int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    char inputLine[MAXLEN] = {0};
    if (fpIn == NULL || fpOut == NULL) 
    {
        exit(1); // выход с ошибкой если файлы не открылись
    } 
    readLine(fpIn, inputLine);
    int lenLine = length(MAXLEN, inputLine);
    (is_palindrom(inputLine)) ?  fprintf(fpOut,"YES\n"): fprintf(fpOut,"NO\n");
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
