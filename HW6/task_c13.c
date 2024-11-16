#include <stdio.h>

// Составить функцию, которая вычисляет косинус как сумму ряда (с точностью 0.001)
// cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)
// float cosinus(float x)

float cosinus(float x);
float power(float n, int p);
int factorial(int n);

int main(int argv, char **argc)
{
    float pi=3.14159;
    int deg;
    float xRadians;
    scanf("%d", &deg);
    if (deg >=0 && deg <=90) {
        xRadians = deg * pi / 180;
        printf("%.3f\n",cosinus(xRadians));
    }
    return 0;
}

float power(float n, int p)
{
    float result = 1; // для степени 0
    if (p > 1)
    {
        for (int i = 1; i <= p; i++)
        {
            result *= n;
        }
    }
    return result;
};

int factorial(int n)
{
    unsigned int result = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            result *= i;
        }
    }
    return result;
}

float cosinus(float x)
{
    return 1 - power(x, 2) / factorial(2) + power(x, 4) / factorial(4) - power(x, 6) / factorial(6);
}