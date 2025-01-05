#include "sensor.h"
#include <stdio.h>
#include <stdint.h>

int monthStatistic(uint64_t size, struct measuring arr[], uint8_t month);
int calcStatistic(uint64_t size, struct measuring arr[], uint8_t month);
uint64_t readFileToArray(FILE *fp, struct measuring *arr);