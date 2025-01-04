#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "sensor.h"
#include "temp_api.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    FILE *fpInp;
    struct measuring arrMessung[MAXLEN];
    char month[3];
    char *monthNames[] = {"январь", "февраль", "март", "апрель",
                          "май", "июнь", "июль", "август",
                          "сентябрь", "октябрь", "ноябрь", "декабрь"};
    char fileName[100];
    menu(argc, argv, fileName, month);
    if (strlen(fileName) > 0)
    {
        printf("Для обработки выбраны: \n\tфайл измерений --> %s%s%s\n", GREEN, fileName, RESET);
    }
    else
    {
        printf("Не выбран файл измерений! Для справки используйте ключ: -h\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
        return 1;
    }
    fpInp = fopen(fileName, "r");
    if (fpInp == NULL)
    {
        printf("Файл %s не найден.\n\t%sАварийный выход из программы!!!%s\n\n", fileName, RED, RESET);
        exit(1);
    }
    if (strlen(month) > 0)
    {
        uint8_t numberMonth;
        sscanf(month, "%hhd", &numberMonth);
        if (numberMonth < 1 || numberMonth > 12)
        {
            printf("Недопусимый номер месяца! Значение должно быть от 1 до 12.\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
            exit(1);
        }
        printf("\tстатистика за  --> %s%s%s\n", GREEN, monthNames[numberMonth - 1], RESET);
        monthStatistic(fpInp, arrMessung, numberMonth);
    }
    else
    {
        printf("\tстатистика за  --> %sгод%s\n", GREEN, RESET);
        yearStatistic(fpInp, arrMessung);
    }
    fclose(fpInp);
    return 0;
}