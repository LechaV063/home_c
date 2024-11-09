#include <stdio.h>

int main(int argv, char ** argc) {
    int n;
    scanf("%d", &n);
    if (n<=100) {
    for (int i=1;i<=n;i++) {
        printf("%d %d %d\n", i, i*i, i*i*i);
        }
    }
    return 0;
}