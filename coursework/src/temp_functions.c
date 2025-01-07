#include "temp_functions.h"
char *monthNames[] = {"янв", "фев", "мар", "апр",
                      "май", "июн", "июл", "авг",
                      "сен", "окт", "ноя", "дек"};

static void printLine(void){
    printf("------------------------------------------\n");
}
 
static void printHeader(void)
{
    printLine();
    printf("| Год  | Месяц | Т.сред | Т.макс | Т.мин |\n");
    printLine();
}

static void printEmpty(int year, int month)
{
    printf("|%5d |  %s  |%sнет данных для обработки!%s|\n", year, monthNames[month - 1], RED, RESET);
    printf("------------------------------------------\n");
};

static void printResult(int year, int month, int min, int max, float avg)
{

    printf("|%5d |  %s  | %s%6.2f%s |    %s%3d%s |   %s%3d%s |\n",
           year, monthNames[month - 1], YELLOW, avg, RESET, RED, max, RESET, BLUE, min, RESET);
    // printf("------------------------------------------\n");
}

int monthStatistic(uint64_t size, struct measuring arr[], uint8_t month)
{
    uint64_t count = 0;
    int64_t summTemp = 0;
    int year, mon, temp; // вспомогательные переменные
    int maxTemp = -99, minTemp = 99;
    float avrgTemp;
    for (size_t i = 0; i < size; i++)
    {
        year = (arr + i)->year;
        mon = (arr + i)->month;
        temp = (arr + i)->temperature;
        if (month == 0) // для годовой статистики
        {
            maxTemp = (temp > maxTemp) ? temp : maxTemp;
            minTemp = (temp < minTemp) ? temp : minTemp;
            summTemp += temp;
            count++;
        }
        else if (mon == month) // статистика за выбранный месяц
        {
            maxTemp = (temp > maxTemp) ? temp : maxTemp;
            minTemp = (temp < minTemp) ? temp : minTemp;
            summTemp += temp;
            count++;
        }
    }
    avrgTemp = (1.0 * summTemp) / count;
    if (month && count > 0)
    {
        printResult(year, month, minTemp, maxTemp, avrgTemp);
    }
    else if (month && count == 0)
    {
        printEmpty(year, month);
    }
    else if (month == 0 && count > 0)
    {
        printf("Годовая статистика: средняя %5.2f C, макс %d C, миним %d C температуры.\n", avrgTemp, maxTemp, minTemp);
    }
    else
    {
        printf("В файле нет данных\n");
        return 1;
    }
    return 0;
};

int calcStatistic(uint64_t size, struct measuring arr[], uint8_t month)
{
    printHeader();
    if (month) // выбрана статистика за 1 месяц
    {
        monthStatistic(size, arr, month); // статистика за выбранный месяц
        printLine();
    }
    else // выбрана статистика за год
    {
        for (size_t i = 1; i <= 12; i++)
        {
            monthStatistic(size, arr, i); // статистика по каждому месяцу
        }
        printLine();
        monthStatistic(size, arr, 0); // общегодовая статистика
    }
    return 0;
};

uint64_t readFileToArray(FILE *fp, struct measuring *arr) // читает файл в масссив-структуру типа measuring
{
    uint64_t count = 0;
    int numberParams, year, mon, day, hour, min, temp;
    while ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) > 0)
        if (numberParams < 6)
        {
            char s[30];
            numberParams = fscanf(fp, "%[^\n]", s);
            LW("Ошибка обработки строки")
            printf("ERROR %d=%s\n", numberParams, s);
        }
        else
        {
            arr->year = year;
            arr->month = mon;
            arr->day = day;
            arr->hour = hour;
            arr->minute = min;
            arr->temperature = temp;
            arr++;
            count++;
        }
    return count; // возвращает количество прочитанных измерений
};