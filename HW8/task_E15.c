#include <stdio.h>

// Постановка задачи:
// Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам:
// в одни помещать только положительные, во второй - только отрицательные.
// Числа, равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.
// Входные данные: 10 целых чисел через пробел.
// Выходные данные: Сперва положительные числа, потом отрицательные числа, через пробел.

const int LENGTH = 10;                                                   // длина массива
int inputData(int *arr, int n);                                          // для заполнения массива, возращает индекс последнего элемента
void printNonZeroData(int *arr, int n);                                  // выводит элементы массива через пробел
void splitArray(int *inpArr, int n, int *pozitiveArr, int *negativeArr); // делит массив на положительный и отрицательный

int main(int argv, char **argc)
{
    int inptArray[LENGTH], pozitiveArray[LENGTH], negativeArray[LENGTH];
    inputData(inptArray, LENGTH);
    splitArray(inptArray, LENGTH, pozitiveArray, negativeArray);
    printNonZeroData(pozitiveArray, LENGTH);
    printNonZeroData(negativeArray, LENGTH);
    printf("\n");
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

void printNonZeroData(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i])
        {
            printf("%d", arr[i]);
            putchar(' ');
        }
    }
};

void splitArray(int *inpArr, int n, int *pozitiveArr, int *negativeArr)
{
    int indexPozitive = 0, indexNegative = 0;
    for (int i = 0; i < n; i++)
        pozitiveArr[i] = negativeArr[i] = 0; // инициализируем нулями выходные массивы
    for (size_t i = 0; i < n; i++)
    {
        if (inpArr[i])
        {
            if (inpArr[i] < 0)
            {
                negativeArr[indexNegative] = inpArr[i];
                indexNegative++;
            }
            else
            {
                pozitiveArr[indexPozitive] = inpArr[i];
                indexPozitive++;
            }
        }
    }
};