#include <stdio.h>
// Условие:
// Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке,
// разделяя их пробелами или новыми строками. Составить рекурсивную функцию.
// Входные данные: Одно не отрицательное целое число
// Выход: Последовательность цифр введенного числа в обратном порядке через пробел

void reversePrint(int num);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    if(userNumber){
    reversePrint(userNumber);
    printf("\n");
    }
    else {
        printf("%d\n", userNumber);
    }
    return 0;
}

void reversePrint(int num)
{
    if (num == 0)
    {
        return;
    }
    printf("%d ", num%10);
    reversePrint(num / 10);
}
