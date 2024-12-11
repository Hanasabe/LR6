#include <iostream>
#include <cstring>
#include "hat.h"
#include <string.h>
void isort1(char*, int);
void hat();
int task22(char*);
int main()
{
    hat();
    while (true)
    {
        char *arr = nullptr;
        arr = (char *)malloc(400 * sizeof(char));
        int i1 = 0;
        std::cout << "Введите текст(после ввода нажмите enter): ";
        while (true)
        {
            if (arr[i1 - 1] != '\n')
                arr[i1] = getchar();
            else
                break;
            i1++;
        }
int cnt = task22(arr);
        std::cout << "\nКоличество предложений текста, в которых есть одинаковые слова: " << cnt << std::endl;
        menu();
    }
}

void hat()
{
    printf("\x1b[1;32m");
    std::cout << "   Задание №2, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[32m");
    std::cout << "   Суть задания: Найти наибольшее количество предложений текста, в которых есть\n"
                 "одинаковые слова.\n\n";
    printf("\x1b[0m");
}

void isort1(char *arr[], int num)
{
    int j;
    char *w;
    for (int i = 1; i < num; ++i)
    {
        w = arr[i];
        j = i - 1;
        while ((j >= 0) && (strcmp(arr[j], w) > 0))
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = w;
    }
}

int task22(char* arr)
{
    int k = 0, i, cnt = 0;
    char *p;

    const char ds[] = " \t\n,";
    const char ps[] = "!?.";
    char **ws = new char *[50];
    for (arr = strtok(arr, ps); arr != NULL; arr = strtok(NULL, ps))
    {
        k = 0;
        while (*arr)
        {
            i = strspn(arr, ds);
            arr += i;
            if (!*arr)
                break;
            p = arr;
            i = strcspn(arr, ds);
            arr += i;
            if (*arr)
                *arr++ = '\0';
            ws[k++] = p;
        }
        int j;
        char *w;
        for (int i = 1; i < k; ++i)
        {
            w = ws[i];
            j = i - 1;
            while ((j >= 0) && (strcmp(ws[j], w) > 0))
            {
                arr[j + 1] = arr[j];
                --j;
            }
            ws[j + 1] = w;
        }
        for (i = 1; i < k; ++i)
        {
            if (!strcmp(ws[i], ws[i - 1]))
            {
                ++cnt;
                break;
            }
        }
    }
    delete[] ws;
    return cnt;
}
