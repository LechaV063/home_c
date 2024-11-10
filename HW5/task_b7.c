#include <stdio.h>

// Ввести целое число и определить, верно ли,
// что в его записи есть две одинаковые цифры,
// НЕ обязательно стоящие рядом.

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
    if (userNumber >= 10) // цифр в числе больше двух?
    {
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
        if (numberOfDigit_9 == 1 ||
            numberOfDigit_1 > 1 ||
            numberOfDigit_2 > 1 ||
            numberOfDigit_3 > 1 ||
            numberOfDigit_4 > 1 ||
            numberOfDigit_5 > 1 ||
            numberOfDigit_6 > 1 ||
            numberOfDigit_7 > 1 ||
            numberOfDigit_8 > 1 ||
            numberOfDigit_9 > 1) // всречается ли цифра в числе более одного раза
        {
            printf("YES\n"); // да встречается
        }
        else
        {
            printf("NO\n"); // нет все цифры в числе уникальны
        }
        return 0;
    }
    else
    {
        printf("NO\n"); // число из одной цифры
    }
}