#include <stdio.h>

int main(int argv, char ** argc) {
    int min, max;
    scanf("%d %d", &min, &max);
    for (int i=min;i<=max;i++) {
        printf("%d ", i*i);
        }
    printf("\n");
    return 0;
}