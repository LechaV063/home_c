#include <stdio.h>

// Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».

int main(int argv, char **argc)
{
    int userNumber, curentDigit;
    int numberOfDigit_0 = 0;
    int numberOfDigit_1 = 0;
    int numberOfDigit_2 = 0;
    int numberOfDigit_3 = 0;
    int numberOfDigit_4 = 0;
    int numberOfDigit_5 = 0;
    int numberOfDigit_6 = 0;
    int numberOfDigit_7 = 0;
    int numberOfDigit_8 = 0;
    int numberOfDigit_9 = 0;
    scanf("%d", &userNumber);
    while (userNumber > 0) // пока не кончатся разряды в числе
    {
        curentDigit = userNumber % 10; // младшая цифра цифра
        userNumber /= 10;
        switch (curentDigit) // подсчёт количества вхождений цифры в число
        {
        case 0:
            numberOfDigit_0++;
            break;
        case 1:
            numberOfDigit_1++;
            break;
        case 2:
            numberOfDigit_2++;
            break;
        case 3:
            numberOfDigit_3++;
            break;
        case 4:
            numberOfDigit_4++;
            break;
        case 5:
            numberOfDigit_5++;
            break;
        case 6:
            numberOfDigit_6++;
            break;
        case 7:
            numberOfDigit_7++;
            break;
        case 8:
            numberOfDigit_8++;
            break;
        case 9:
            numberOfDigit_9++;
            break;
        }
    }
    if (numberOfDigit_9 == 1) // всречается ли цифра 9 в числе ровно 1 раз?
    {
        printf("YES\n"); // да есть одна 9-ка
    }
    else
    {
        printf("NO\n"); // нет количество 9-ок в числе не одна
    }
    return 0;
}
