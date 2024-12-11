#include <iostream>
#include "hat.h"
void hat();
int task(char*, int, int*, int*);
int main()
{
    hat();
    while (true)
    {
        char *arr = (char *)malloc(80 * sizeof(char));
        int i1 = 0;
        int i3 = 0;
        int i5 = 0;
        std::cout << "Введите строку: ";
        while (true)
        {
            if (arr[i1 - 1] != '\n')
                arr[i1] = getchar();
            else
                break;
            i1++;
        }
        int *num_char = new int(i1);
        ;
        int min = task(arr, i1, num_char, &i5);
        std::cout << "\nПорядковый номер слова минимальной длины: " << i5 + 1 << '\n'
                  << '\n';
        std::cout << "Количество символов в этом слове: " << min;
        menu();
        free(arr);
        delete[] num_char;
    }
    return 0;
}

void hat()
{
    printf("\x1b[1;31m");
    std::cout << "   Задание №1, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[31m");
    std::cout << "   Суть задания: Дана строка, состоящая из слов, разделенных пробелами. Вывести\n"
                 "на экран порядковый номер слова минимальной длины и количество\n"
                 "символов в этом слове.\n\n";
    printf("\x1b[0m");
}

int task(char *arr, int i1, int *num_char, int* i5)
{
    for (int i = 0; i < i1; i++)
    {
        num_char[i] = 0;
    }
    int i2 = 0;
    for (int i = 0; i < i1; i++)
    {
        if (arr[i] != ' ' && arr[i] != '\n')
        {
            num_char[i2]++;
        }
        else
        {
            i2++;
        }
    }
    int i4 = 0;
    for (int i = 0; i <= i2; i++)
    {
        if (num_char[i] != 0)
            i4++;
    }
    int min = 80;
    for (int i = 0; i < i4; i++)
    {
        if (num_char[i] <= min)
        {
            min = num_char[i];
            *i5 = i;
        }
    }

    return min;
}