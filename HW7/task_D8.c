#include <stdio.h>
// Условие:
// Составить рекурсивную функцию, Выведите все числа от A до B включительно,
// в порядке возрастания, если A < B, или в порядке убывания в противном случае.
// Входные данные: Два целых числа через пробел.
// Выход: Последовательность целых чисел.

void recursPrintNumbers(int leftNum, int rightNum);

int main(int argv, char **argc)
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    recursPrintNumbers(num1, num2);
    printf("\n");
    return 0;
}

void recursPrintNumbers(int leftNum, int rightNum)
{
    if (leftNum == rightNum)
    {
        printf("%d ", rightNum);
        return;
    }
    if (leftNum > rightNum)
    {
        printf("%d ", leftNum);
        recursPrintNumbers(leftNum - 1, rightNum);
    }
    else
    {
        recursPrintNumbers(leftNum, rightNum - 1);
        printf("%d ", rightNum);
    }
    return;
}