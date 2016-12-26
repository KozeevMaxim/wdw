#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;

double sum(float a, float b)
{
    return a + b;
}

double sub(float a, float b)
{
    return a - b;
}

double mult(float a, float b)
{
    return a * b;
}

int main(int argc, char *argv[])
{
    int a, b;
    if (argc < 3)
    {
        printf_s("Ошибка, параметров в командной строке не хватает для задания исходных данных. Для завершения нажмите любую клавишу\n");
        system("pause");
        return 1;
    }
    if (sscanf_s(argv[1], "%d", &a) < 1)
    {
        printf_s("Ошибка, неверный формат первого входного параметра. Для завершения нажмите любую клавишу\n");
        system("pause");
        return 1;
    }
    if (sscanf_s(argv[2], "%d", &b) < 1)
    {
        printf_s("Ошибка, неверный формат первого входного параметра. Для завершения нажмите любую клавишу\n");
        system("pause");
        return 1;
    }

    cout << "a + b = " << sum(a, b) << endl;
    cout << "a - b = " << sub(a, b) << endl;
    cout << "a * b = " << mult(a, b) << endl;
    system("pause");
    return 0;
}
