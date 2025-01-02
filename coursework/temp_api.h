#ifndef SENSOR
#define SENSOR
#include "sensor.h"
#endif

int avrgMonthTemp(sensor arr[], uint8_t month);
int maxMonthTemp(sensor arr[], uint8_t month);
int minMonthTemp(sensor arr[], uint8_t month);
int avrgYearTemp(sensor arr[]);
int maxYearTemp(sensor arr[]);
int minYearTemp(sensor arr[]);

