#include <stdio.h>
// Условие:
// Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. 
// Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
// Входные данные:Строка из английских букв и знаков препинания. В конце строки символ точка.
// Выход:Исходная строка задом наперед.

void reverse_string();

int main(int argv, char **argc)
{
    reverse_string();
    printf("\n");
    return 0;
}
void reverse_string()
{
    char ch =getchar();
    if(ch=='.') return;
    reverse_string();
    printf("%c", ch);
}