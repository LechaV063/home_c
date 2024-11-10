#include <stdio.h>

// Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.

int main(int argv, char **argc)
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        printf("%d ", i * i); // выводим результат в одну строку
    }
    printf("\n");
    return 0;
}