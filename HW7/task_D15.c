#include <stdio.h>
// Условие:
// Дана последовательность ненулевых целых чисел, завершающаяся числом 0.
// Ноль в последовательность не входит. Определите наибольшее значение числа в этой последовательности.
// Для решения задачи необходимо написать рекурсивную функцию вида:
// Входные данные: Последовательность не нулевых целых чисел. В конце последовательности число 0.
// Выход: Одно число. Максимум последовательности.

int max_find(int max);

int main(int argv, char **argc)
{
    int userNumber = 0;
    scanf("%d", &userNumber);
    if (userNumber == 0)
        return 0;
    printf("%d\n", max_find(userNumber));
    return 0;
}

int max_find(int max)
{
    int num;
    int temp;
    scanf("%d", &num);
    if (num == 0)
    {
        return max;
    }
    max = max > num ? max : num;
    temp = max_find(max);
    return max > temp ? max : temp;
};