#include <stdio.h>

//  Составить функцию, модуль числа и привести пример ее использования.

int absolute(int num);

int main(int argv, char ** argc) {
    int userNumber;
    scanf("%d", &userNumber);
    printf("%d\n", absolute(userNumber));
    return 0;
}

int absolute (int num) {
    int result = num < 0 ? -1 * num :  num;
    return result;
}