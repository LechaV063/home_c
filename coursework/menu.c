#include "menu.h"

void help(void)
{
    printf("Приложение sensor выводит статистику измерений температуры \nза выбранный месяц или год в зависимости от выбранных опций.\n");
    printf("Вычисляет:\n\
    - минимальную,\n\
    - максимальную и\n\
    - среднюю температуры.\n");
    printf("Формат вызова:\n\
    ./sensor [-h] -f filename [-m NN]\n");
    printf("-h вызов справки (опциональный),\n");
    printf("-f filename имя файла с измерениями (обязательный),\n");
    printf("-m NN \tномер месяца от 1 до 12 (опциональный),\n\tесли не указан, то обрабатывается весь год.\n");
}

void menu(int argc, char *argv[], char *filename, char *mon)
{
    int result = 0;
    if (argc == 1)
    {
        printf("Нет обязательного ключа -f. Для справки используйте ключ: -h\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
        exit(1);
    }
    while ((result = getopt(argc, argv, "hm:f:")) != -1)
    {
        switch (result)
        {
        case 'm':
            char *tmp = optarg;
            if (tmp == NULL || strlen(tmp) > 2)
            {
                printf("Недопусимое количество символов для номера месяца\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
                exit(1);
            }
            else
            {
                strcpy(mon, optarg);
            }
            break;
        case 'f':
            tmp = optarg;
            if (tmp == NULL)
            {
                printf("Не задано имя для файла измерений!\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
                exit(1);
            }
            strcpy(filename, optarg);
            break;
        case '?':
            printf("Неизвестная опция или нет обязательного аргумента. Для справки используйте ключ: -h\n\t%sАварийный выход из программы!!!%s\n\n", RED, RESET);
            exit(1);
        case 'h':
            help();
            exit(0);
        }
    }
}
