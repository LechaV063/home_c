#include <stdio.h>

int main(void) {
    int a, b;    
    scanf("%d %d", &a, &b);
    a > b? printf("%d %d\n", b, a):printf("%d %d\n", a, b);
}
