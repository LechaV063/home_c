#include "temp_api.h"

static void printResult(int min, int max, int avg)
{
    printf("Результат обработки:\n");
    printf("Минимальная  температура: %s%3d C%s\n", GREEN, min, RESET);
    printf("Максимальная температура: %s%3d C%s\n", GREEN, max, RESET);
    printf("Средняя      температура: %s%3d C%s\n", GREEN, avg, RESET);
}

int monthStatistic(FILE *fp, struct measuring arr[], uint8_t month)
{
    uint64_t count = 0;
    int64_t summTemp = 0;
    int numberParams, year, mon, day, hour, min, temp;
    int maxTemp, minTemp, avrgTemp;
    printf("Идёт расчёт...\n");
    if ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) == 6)
        maxTemp = minTemp = temp;
    while ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) == 6)
    {
        // printf("%02d-%02d-%4d %02d:%02d --> %d\n", day, mon, year, hour, min, temp);
        if (mon == month)
        {
            count++;
            summTemp += temp;
            maxTemp = (temp > maxTemp) ? temp : maxTemp;
            minTemp = (temp < minTemp) ? temp : minTemp;
        }
    }
    printResult(minTemp, maxTemp, (int)summTemp / count);
    return 0;
};
int yearStatistic(FILE *fp, struct measuring arr[])
{
    uint64_t count = 0;
    int64_t summTemp = 0;
    int numberParams, year, mon, day, hour, min, temp;
    int maxTemp, minTemp, avrgTemp;
    printf("Идёт расчёт...\n");
    if ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) == 6)
        maxTemp = minTemp = temp;
    while ((numberParams = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &mon, &day, &hour, &min, &temp)) == 6)
    {
        // printf("%02d-%02d-%4d %02d:%02d --> %d\n", day, mon, year, hour, min, temp);
        count++;
        summTemp += temp;
        maxTemp = (temp > maxTemp) ? temp : maxTemp;
        minTemp = (temp < minTemp) ? temp : minTemp;
    }
    printResult(minTemp, maxTemp, (int)summTemp / count);
    return 0;
};
