#include <stdio.h>

//  Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
// sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)

float sinus(float x);
float power(float n, int p);
int factorial(int n);

int main(int argv, char ** argc) {
    float pi=3.14159;
    int deg;
    float xRadians;
    scanf("%d", &deg);
    if (deg >=0 && deg <=90) {
        xRadians = deg * pi / 180;
        printf("%.3f\n",sinus(xRadians));
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

float sinus(float x) {
    return x - power(x,3)/factorial(3) + power(x,5)/factorial(5) - power(x,7)/factorial(7);
}