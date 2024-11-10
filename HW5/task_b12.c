#include <stdio.h>
// Организовать ввод натурального числа с клавиатуры.
//  Программа должна определить наименьшую и наибольшую цифры,
//  которые входят в состав данного натурального числа.
//  Целое неотрицательное число
int main(int argv, char **argc)
{
    int userNumber,
        minDigit = 9, // стартовое значение для минимальной цифры
        maxDigit = 0, // стартовое значение для максимальной цифры
        currentDigit;
    scanf("%d", &userNumber);
    if (userNumber > 0)
    {
        if (userNumber >= 10)
        {
            currentDigit = userNumber % 10; // обработка 1-го разряда числа
            maxDigit = currentDigit > maxDigit ? currentDigit : maxDigit;
            minDigit = currentDigit < minDigit ? currentDigit : minDigit;
            while (userNumber / 10 > 0) // проход по цифрам со 2-го разряда
            {
                userNumber /= 10;
                currentDigit = userNumber % 10;
                maxDigit = currentDigit > maxDigit ? currentDigit : maxDigit;
                minDigit = currentDigit < minDigit ? currentDigit : minDigit;
            }
            printf("%d %d\n", minDigit, maxDigit);
        }
        else
        {
            minDigit = maxDigit = userNumber; // когда число из одной цифры
            printf("%d %d\n", minDigit, maxDigit);
        }
        return 0;
    }
    return 1; // число не положительное
}