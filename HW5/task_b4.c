#include <stdio.h>
// Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.
// Целое положительное число
int main(int argv, char **argc)
{
    int number, i = 0;
    scanf("%d", &number);
    if (number > 0) // проверка введённого числа
    {
        while (number > 0)
        {
            number /= 10;
            i++;
        }
        i == 3 ? printf("YES\n") : printf("NO\n");
        return 0;
    }
    return 1; // ошибка ввода
}