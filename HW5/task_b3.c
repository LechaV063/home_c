#include <stdio.h>

// Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
// Два целых числа по модулю не больше 100

int main(int argv, char **argc)
{
    int a, b, sum = 0;
    scanf("%d %d", &a, &b);
    if (a <= 100 && b <= 100 && a <= b) // числа не должны быть больше 100
    {
        for (int i = a; i <= b; i++)
        {
            sum += i * i;
        }
        printf("%d\n", sum);
        return 0;
    }
    return 1; // код ошибки 1, так как входные условия не прошли
}