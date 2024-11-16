#include <stdio.h>

//  Составить функцию логическую функцию, которая определяет, верно ли,
// что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.

int grow_up(int n);

int main(int argv, char **argc)
{
    int userNumber;
    scanf("%d", &userNumber);
    grow_up(userNumber) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int grow_up(int n) // возращает 1 если цифры в числе по возрастанию, 0 - в противном случае 
{
    int digitLeft, digitRight, result = 1;
    if (n >= 10)
    {
        digitRight = n % 10;
        while (n > 0)
        {
            n /= 10;
            digitLeft = n % 10;
            if (digitLeft >= digitRight)
            {
                result = 0;
                break;
            }
            else
            {
                digitRight = digitLeft;
            }
        }
    }
    return result;
}
