#include "sensor.h"
#include <stdio.h>
#include <stdint.h>

int monthStatistic(FILE *fp, struct measuring arr[], uint8_t month);
int yearStatistic(FILE *fp, struct measuring arr[]);
