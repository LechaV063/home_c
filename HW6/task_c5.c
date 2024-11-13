#include <stdio.h>

//  Составить функцию, которая определяет сумму всех чисел от 1 до N 
// и привести пример ее использования.

int ariphProgres(int n);

int main(int argv, char ** argc) {
    int userNumber;
    scanf("%d", &userNumber);
    printf("%d\n", ariphProgres(userNumber));
    return 0;
}

int ariphProgres(int n){
    return (n+1)*n/2;
}