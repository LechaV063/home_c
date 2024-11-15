#include <stdio.h>

//  Составить функцию, возведение числа N в степень P.
// int power(n, p) и привести пример ее использования.

int power(int n, int p);

int main(int argv, char **argc)
{
    int N, P;
    scanf("%d %d", &N, &P);
    if (N <= 1000 && P <= 1000 && P >= 0) // Проверка корректности ввода
    {
        printf("%d\n", power(N, P));
    }
    return 0;
}

int power(int n, int p)
{
    int result = 1; // для степени 0
    if (p > 1)
    {
        for (int i = 1; i <= p; i++)
        {
            result *= n;
        }
    }
    return result;
};
