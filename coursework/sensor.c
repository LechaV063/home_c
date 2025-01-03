#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "sensor.h"
#include "temp_api.h"
#include "menu.h"

int main(int argc, char *argv[])
{
    struct sensor arrMessung[MAXLEN];
    char month[3];
    char fileName[100];
    menu(argc, argv, fileName, month);
    printf("Выбран файл измерений: %s\n", fileName);
    if (month != NULL)
    {
        uint8_t numberMonth;
        sscanf(month, "%hhd", &numberMonth);
        monthStatistic(arrMessung, numberMonth);
    }
    else
    {
        yearStatistic(arrMessung);
    }
    return 0;
}