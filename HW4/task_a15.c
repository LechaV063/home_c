#include <stdio.h>

int main (void) {
    int x1, x2, y1, y2;
    float k, b;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    k = (y1 - y2)*1.0/(x1 -x2);
    b = y1 - (k * x1);
    printf("%.2f %.2f\n", k, b);
}