#include <stdio.h>

int main(int argv, char ** argc) {
    int number, i=0 , sum=0 , digit;
    
    scanf("%d", &number);
    if (number >= 0) {
    while (number > 0)
    {
        digit=number%10;
        // printf("digit: %d\n", digit);
        number /= 10;
        // printf("number: %d\n", number);
        sum += digit;
    }   
    printf("%d\n", sum);
    }
    return 0;
}