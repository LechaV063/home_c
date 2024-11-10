#include <stdio.h>

int main(int argv, char ** argc) {
    int n;
    scanf("%d", &n);
    if (n<=100) {  // число должно быть меньше 100 по условию
    for (int i=1;i<=n;i++) {
        printf("%d %d %d\n", i, i*i, i*i*i); // вывод текущего числа и его квадрата и куба
        }
    }
    return 0;
}