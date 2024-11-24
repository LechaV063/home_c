#include <stdio.h>

// Постановка задачи:
// Считать массив из 10 элементов и выделить в другой массив все числа,
// которые встречаются более одного раза.
// В результирующем массиве эти числа не должны повторяться.
// Входные данные: 10 целых чисел через пробел
// Выходные данные: Целые числа через пробел,
// которые встречаются более одного раза в исходном массиве.

const int LENGTH = 10;                               // длина массива
int inputData(int *arr, int n);                      // для заполнения массива, возращает индекс последнего элемента
void printData(int *arr, int n);                     // выводит элементы массива через пробел
int repeatValArray(int *inpArr, int *resArr, int n); // делает массив с повторяющимися значениями исходного массива

int main(int argv, char **argc)
{
    int inptArray[LENGTH], resultArray[LENGTH / 2];
    int lenResult;
    inputData(inptArray, LENGTH);
    lenResult = repeatValArray(inptArray, resultArray, LENGTH);
    printData(resultArray, lenResult);
    return 0;
}
int inputData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    return i;
};

void printData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1) // после последнего элемента пробел не пишим
        {
            putchar(' ');
        }
    }
    putchar('\n');
};

int repeatValArray(int *inpArr, int *resArr, int n)
{
    int index = 0, isRepeat = 0;
    int markArray[n];              //
    for (size_t i = 0; i < n; i++) // инициализация массива с признаком повтора
    {
        markArray[i] = 0; // по умолчанию повторов нет
    }
    for (int i = 0; i < n; i++)
    {
        if (!markArray[i]) // если был повтор пропускаем
        {
            for (int j = i + 1; j < n; j++)
            {
                if (inpArr[i] == inpArr[j] && !markArray[j]) // нашёлся повтор и его ранее не было
                {
                    if (!markArray[i])
                    {
                        resArr[index] = inpArr[i];
                        index++;
                        markArray[i] = 1; // ставим маркировку
                    }
                    markArray[j] = 1; // ставим маркировку
                }
            }
        }
    }
    return index;
};