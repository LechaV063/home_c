#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "sensor.h"
#include "temp_api.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    struct measuring arrMessung[MAXLEN];
    char month[3];
    char *months[] = {"январь", "февраль", "март", "апрель",
                      "май", "июнь", "июль", "август",
                      "сентябрь", "октябрь", "ноябрь", "декабрь"};
    char fileName[100];
    menu(argc, argv, fileName, month);
    if (strlen(fileName) > 0)
    {
        printf("Для обработки выбраны: \n- файл измерений --> %s%s%s\n", GREEN, fileName, RESET);
    }
    else
    {
        printf("Не выбран файл измерений! Для справки используйте ключ: -h\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
        return 1;
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
        printf("- статистика за  --> %s%s%s\n", GREEN, months[numberMonth - 1], RESET);
        monthStatistic(arrMessung, numberMonth);
    }
    else
    {
        printf("- статистика за  --> %sгод%s\n", GREEN, RESET);
        yearStatistic(arrMessung);
    }
    return 0;
}