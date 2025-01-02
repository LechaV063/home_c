#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "sensor.h"
// #include "temp_api.h"

int main(int argc, char *argv[])
{
    int result = 0;
    sensor arrMessung[MAXLEN];
    while ((result = getopt(argc, argv, "hm::f:")) != -1)
    {
        switch (result)
        {
        case 'h':
            printf("Вызов программы:  ./sensor -mN -f filename\n");
            printf("где:\n");
            printf("N\t\t- номер месяца\nfilename\t- имя файла с измерениями.\n");
            break;
        case 'm':
            printf("option %c selected with argument \n", result);
            break;
        case 'f':
            printf("option %c selected file: \n", result);
            break;
        case '?':
            printf("option %c selected\n", result);
            break;
        }
    }
    return 0;
}