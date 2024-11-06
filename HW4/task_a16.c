#include <stdio.h>

int main (void) {
    int number1, number2, number3;
    scanf("%d %d %d", &number1, &number2, &number3);
    if (number1 < number2 && number2 < number3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
