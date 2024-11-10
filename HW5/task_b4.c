#include <stdio.h>

int main(int argv, char ** argc) {
    int number, i=0 ;
    scanf("%d", &number);
    while (number > 0)
    {
        number /= 10;
        i++ ;

    }   
    i == 3 ? printf("YES\n") : printf("NO\n");
    return 0;
}