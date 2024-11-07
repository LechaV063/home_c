#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("Equal\n");
    } else if (a > b) {
        printf("Above\n");
    } else {
        printf("Less\n");
    }
}
