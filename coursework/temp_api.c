#include "temp_api.h"
char *monthNames[] = {"янв", "фев", "мар", "апр",
                      "май", "июн", "июл", "авг",
                      "сен", "окт", "ноя", "дек"};

static void printHeader(void)
{
    printf("Результат обработки:\n");
    printf("------------------------------------------\n");
    printf("| Год  | Месяц | Т.сред | Т.макс | Т.мин |\n");
    printf("------------------------------------------\n");
}

static void printEmpty(int year, int month)
{
    printf("|%5d |  %s  |%sнет данных для обработки!%s|\n", year, monthNames[month - 1], RED, RESET);
    printf("------------------------------------------\n");
};

static void printResult(int year, int month, int min, int max, int avg)
{

    printf("|%5d |  %s  |    %s%3d%s |    %s%3d%s |   %s%3d%s |\n",
           year, monthNames[month - 1], YELLOW, avg, RESET, RED, max, RESET, BLUE, min, RESET);
    printf("------------------------------------------\n");
}

int monthStatistic(uint64_t size, struct measuring arr[], uint8_t month)
{
    uint64_t count = 0;
    int64_t summTemp = 0;
    int numberParams, year, mon, day, hour, min, temp;
    int maxTemp = -99, minTemp = 99, avrgTemp;
    for (size_t i = 0; i < size; i++)
    {
        year = (arr + i)->year;
        mon = (arr + i)->month;
        day = (arr + i)->day;
        hour = (arr + i)->hour;
        min = (arr + i)->minute;
        temp = (arr + i)->temperature;
        if (mon == month)
        {
            maxTemp = (temp > maxTemp) ? temp : maxTemp;
            minTemp = (temp < minTemp) ? temp : minTemp;
            summTemp += temp;
            count++;
        }
    }
    if (count > 0)
    {
        printResult(year, month, minTemp, maxTemp, (int)summTemp / count);
    }
    else
    {
        printEmpty(year, month);
    }
    return 0;
};

int calcStatistic(uint64_t size, struct measuring arr[], uint8_t month)
{
    uint64_t count = 0;
    int64_t summTemp = 0;
    int numberParams, year, mon, day, hour, min, temp;
    int maxTemp, minTemp, avrgTemp;
    printHeader();
    if (month)
    {
        monthStatistic(size, arr, month);
    }
    else
    {
        for (size_t i = 1; i <= 12; i++)
        {
            monthStatistic(size, arr, i);
        }
        monthStatistic(size, arr, 0);
    }
    return 0;
};

uint64_t readFileToArray(FILE *fp, struct measuring *arr)
{
    uint64_t count = 0;
    int numberParams, year, mon, day, hour, min, temp;
    while ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) == 6)
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
    return count;
};