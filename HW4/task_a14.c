#include <stdio.h>

int main(void) {
    int digit_1=0,digit_2=0,digit_3=0;    
    int number, max;
    scanf("%d", &number);
    digit_1 = number / 100;
    digit_2 = (number - digit_1 * 100)/10;
    digit_3 = (number - digit_1 * 100 - digit_2 * 10);
    max = digit_1 > digit_2 ? digit_1 : digit_2;
    max = max > digit_3 ? max : digit_3 ;
    printf("%d\n", max);
}