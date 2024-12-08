#include <stdio.h>

// Постановка задачи:
// Считать число N из файла input.txt. Сформировать строку из N символов.
// N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
// на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
// Результат записать в файл output.txt
// Входные данные:
// Выходные данные:

const char inputFileName[10] = "input.txt";
const char outputFileName[11] = "output.txt";

int main(int argv, char **argc)
{
    FILE *fpIn, *fpOut;
    fpIn = fopen(inputFileName, "r");
    fpOut = fopen(outputFileName, "w");
    if (fpIn != NULL && fpOut != NULL) // проверка открылись ли файлы
    {
        int userNumber, evenDigit = 0;
        char ch;
        fscanf(fpIn, "%d", &userNumber);
        if (userNumber >= 0 && userNumber <= 26)
        {
            for (size_t i = 1; i <= userNumber; i++)
            {
                if (i % 2)
                {
                    ch = 'A' + i / 2;
                }
                else
                {
                    evenDigit += 2;
                    evenDigit = (evenDigit == 10) ? 2 : evenDigit;
                    ch = '0' + evenDigit;
                }
                putc(ch, fpOut);
            }
        }
    }
    fclose(fpOut);
    fclose(fpIn);
    return 0;
}
