#include <stdio.h>

int main(void) {
    int digit_1=0,digit_2=0,digit_3=0;    
    int number;
    scanf("%d", &number);
    digit_1 = number / 100;
    digit_2 = (number - digit_1 * 100)/10;
    digit_3 = (number - digit_1 * 100 - digit_2 * 10);
    printf("%d\n", digit_1+digit_2+digit_3);
}