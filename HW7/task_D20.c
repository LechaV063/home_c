#include <stdio.h>
// Условие:
// Написать рекурсивную функцию возведения целого числа n в степень p.
// Используя данную функцию, решить задачу.
// Входные данные: Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100
// Выход: Одно целое число n в степени p

int recurs_power(int n, int p);

int main(int argv, char **argc)
{
    int n, p;
    scanf("%d %d", &n, &p);
    if (p == 0)
    {
        printf("1\n");
        return 0;
    }
    printf("%d\n", recurs_power(n, p));
    return 0;
}

int recurs_power(int n, int p)
{
    if (p == 1)
    {
        return n;
    }
    return n * recurs_power(n, p - 1);
};