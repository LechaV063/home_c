#include <stdio.h>

//  Составить функцию логическую функцию, которая определяет,
// верно ли, что число простое. Используя функцию решить задачу.
int is_prime(int n);

int main(int argv, char **argc)
{
    int userNumber, simple = 1;
    scanf("%d", &userNumber);
    is_prime(userNumber) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int is_prime(int n)
{
    int simple = 1;
    if (n == 1 || n == 0)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0 && n / i > 0)
        {
            simple = 0;
            break;
        }
    }
    return simple;
}
