#include <stdio.h>

// Ввести целое число и «перевернуть» его,
// так чтобы первая цифра стала последней и т.д.

int main(int agrv, char **argc)
{
    int userNumber, reverseNumber = 0, currentDigit;
    scanf("%d", &userNumber);
    reverseNumber = userNumber % 10; // старшая цифра цисла вперёд
    if (userNumber > 10)
    {
        do
        {
            userNumber /= 10;
            reverseNumber *= 10; // сдвиг на разряд влево
            currentDigit = userNumber % 10;
            reverseNumber += currentDigit; // очередная цифра в младший разряд
        } while (userNumber / 10 > 0);
    }
    printf("%d\n", reverseNumber);
    return 0;
}