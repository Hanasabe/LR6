#include <iostream>
#include "hat.h"
void hat();
void taskk3(char*, int);
int main()
{
    hat();
    while (true) {

    int i1 = 0;
    char *arr = new char[100];
    std::cout << "Введите строку: ";

    while (true)
    {
        if (arr[i1 - 1] != '\n')
            arr[i1] = getchar();
        else
            break;
        i1++;
    }

    taskk3(arr, i1);

    std::cout << "\nПолученная строка: ";
    for (int i = 0; i < i1; i++)
    {
        if (arr[i] != '#')
            std::cout << arr[i];
    }

    menu();
    delete[] arr;

    }
    return 0;
}

void hat()
{
    printf("\x1b[1;33m");
    std::cout << "   Задание №3, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[33m");
    std::cout << "   Суть задания: Найти наибольшее количество предложений текста, в которых есть\n"
                 "одинаковые слова.\n\n";
    printf("\x1b[0m");
}

void taskk3 (char* arr, int i1) {
    int num = 0, q, q2;
    int qw;
    for (int i6 = 0; i6 < i1;)
    {
        for (int i = i6; i < i1; i++)
        {
            if (arr[i + 1] == '#')
                num++;
                qw = i;
            if ((arr[i] == '#' && arr[i + 1] != '#') || i == i1)
                break;
        }
        q = num * 2;
        bool we = true;
        q2 = i6;
        int i9 = 0;
        if (q == 0)
        break;
        for (int i = q2; i < i1;)
        {
            we = true;
            if (arr[i + 1] == '#' && num != 0)
            {
                arr[i] = '#';
                i9 = i;
                num--;
                if (i != i6)
                {
                    i--;
                }
                we = false;
            }
            if (num == 0)
            {
                i6 = i9 + q;
                break;
            }
            if (num != 0 && we)
                i++;
        }
    }
}
