#include <stdio.h>

// Ввести целое число и определить, верно ли,
// что в его записи есть две одинаковые цифры, стоящие рядом

int main(int argv, char ** argc) {
    int number, digit_prev=0, digit_current=0;   
    scanf("%d", &number);
    if (number >= 10) // цифр меньше двух?
        {
        digit_prev = number%10; // предыдущая цифра
        number /= 10;
        while (number > 0) // пока не кончатся разряды в числе 
            {
                digit_current=number%10; // получаем текущую цифру
                if (digit_current != digit_prev) {
                number /= 10;
                digit_prev = digit_current;
                } else {
                    printf("YES\n"); // нашли совпадение текущей и предудущей цифр
                    return 0; // дальше можно не искать
                }
            }   
            printf("NO\n");  // цикл окончен - совпадений нет
            return 0;
        }
    printf("NO\n"); // цифр меньше двух - совпадений не будет
    return 0;
}