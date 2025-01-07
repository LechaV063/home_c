#include <stdint.h>
#include "colors.h"
#ifndef SENSOR
#define SENSOR
#define MAXLEN 60*24*365

struct measuring
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

#endif