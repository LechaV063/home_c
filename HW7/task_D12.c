#include <stdio.h>
// Условие:
// Дана монотонная последовательность, в которой каждое натуральное число k
// встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
// Выведите первые n членов этой последовательности. Только один цикл for.
// Входные данные: Натуральное число.
// Выход: Последовательность целых чисел.

void printSquence(int num);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    printSquence(userNumber);
    return 0;
}

void printSquence(int num) // возвращает количество оставшихся итераций
{
    static int count = 1;
    if (num <= 0)
    {
        return;
    }
    for (int i = 1; i <= count; i++)
    {
        if (num > 0)
        {
            printf("%d ", count);
            num--;
        } else {
            return;
        }
    }
    count++;
    printSquence(num);
}