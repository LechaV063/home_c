#include <stdio.h>

int main(int argv, char ** argc) {
    int min, max, sum=0;
    scanf("%d %d", &min, &max);
    for (int i=min;i<=max;i++) {
        sum += i*i;
        }
    printf("%d\n", sum);
    return 0;
}