#include "menu.h"

void help(void)
{
    printf("Приложение sensor выводит статистику измерений температуры \nза выбранный месяц/год (зависит от выбранных опций).\n");
    printf("Вычисляет:\n\t- минимальную, \n\t- максимальную и \n\t- среднюю температуры.\n\n");
    printf("Параметры вызова: ./sensor [-h] -f filename [-m NN]\n");
    printf("-h вызов справки.\n");
    printf("-f filename имя файла с измерениями,\n");
    printf("-m NN номер месяца от 1 до 12, если опция не указана, то обрабатывается год.\n\n");
}

void menu(int argc, char *argv[], char *filename, char *month)
{
    int result = 0;
    while ((result = getopt(argc, argv, "hm:f:")) != -1)
    {
        switch (result)
        {
        case 'm':
            char *tmp = optarg;
            if (tmp == NULL || strlen(tmp) > 2)
            {
                printf("Недопусимое количество символов для номера месяца\n");
                exit(1);
            }
            else
            {
                strcpy(month, optarg);
            }
            break;
        case 'f':
            tmp = optarg;
            if (tmp == NULL)
            {
                printf("Не задано имя для файла измерений!\n");
                exit(1);
            }
            strcpy(filename, optarg);
            break;
        case '?':
            printf("Неизвестная опция.\n");
        case 'h':
            help();
            exit(0);
        }
    }
}
