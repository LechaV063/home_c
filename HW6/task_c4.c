#include <stdio.h>

//  Описать функцию вычисления f(x) по формуле: 
// f(x)= x*x при -2 ≤ x < 2;
// x*x+4x+5 при x ≥ 2;
// 4 при x < -2.
// Используя эту функцию для n заданных чисел, вычислить f(x).
// Среди вычисленных значений найти наибольшее.

int f(int x) // реализация функции из условия
{
    int result = 0;
    if (x >= -2 && x < 2)
    {
        result = x * x;
    }
    if (x >= 2)
    {
        result = x * x + 4 * x + 5;
    }
    if (x < -2)
    {
        result = 4;
    }
    return result;
}

int main(int argv, char **argc)
{
    int number, max = 0;
    scanf("%d", &number);
    max = f(number); // функция от первого числа - текущий максимум
    while (number != 0)
    {
        scanf("%d", &number);
        int fCuccernt = f(number);
        max = fCuccernt > max ? fCuccernt : max; // кто больше
    }
    printf("%d\n", max);
    return 0;
}