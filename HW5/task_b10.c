#include <stdio.h>

int main(int argv, char **argc)
{
    int userNumber, rightDigit, leftDigit;
    scanf("%d", &userNumber);
    if (userNumber/10 == 0)
    {
        goto good; // одна цифра - условие выполнено
    }    
    do
    {
        rightDigit = userNumber % 10;
        userNumber /= 10;
        leftDigit = userNumber % 10;
        if (rightDigit <= leftDigit)
        {
            goto fall; // условие возрастания цифр нарушено
        }
    } while (userNumber > 0);
good:
    printf("YES\n");
    return 0;
fall:
    printf("NO\n");
    return 0;
}
