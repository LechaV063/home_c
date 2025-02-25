#include <stdio.h>

// Ввести целое число и определить, верно ли, что все его цифры четные.

int main(int argv, char ** argc) 
{
    int userNumber, curentDigit;
    scanf("%d", &userNumber);
    while ( userNumber > 0) // пока не кончатся разряды в числе 
        {
            curentDigit = userNumber%10; // младшая цифра цифра
            if (curentDigit%2 != 0) { // проверка на нечётность
                printf("NO\n"); // найдена первая нечётная цифра
                return 0;
            }
            userNumber /= 10;
        }
    printf("YES\n"); // все цифры оказались чётные
    return 0;
}

