#include <stdio.h>

// Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

int main(int argv, char **argc)
{
    int userNumber, sumDigits;
    scanf("%d", &userNumber);
    sumDigits = userNumber%10;
    while (userNumber/10>0)
    {
        userNumber /=10;
        sumDigits += userNumber%10;
    }
    (sumDigits == 10) ? printf("YES\n") : printf("NO\n");
    return 0;
}