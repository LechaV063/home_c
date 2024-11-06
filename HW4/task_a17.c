#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

int main (void) {
    uint8_t month;
    scanf("%" SCNu8, &month);
    if (month == 12 || month == 1 || month == 2) {
        printf("winter\n");
    } else if (month == 3 || month == 4 || month == 5) {
        printf("spring\n");
    } else if (month == 6 || month == 7 || month == 8) {
        printf("summer\n");
    } else {
        printf("autumn\n");
    }
}