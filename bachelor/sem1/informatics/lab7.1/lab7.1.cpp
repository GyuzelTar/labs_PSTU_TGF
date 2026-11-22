// Лабораторная работа № 7. Перегрузка функций в Си++. Вариант 23.
// Чётный первый элемент - сдвиг влево на a[0] позиций,
// нечётный - сдвиг вправо на a[n-1] позиций (элементы считаем неотрицательными).
#include <iostream>
using namespace std;

void shift_array(int n, int a[])
{
    int i, j, k, t;
    if (a[0] % 2 == 0)              // первый элемент чётный
    {
        k = a[0] % n;
        for (j = 1; j <= k; j++)    // сдвиг влево на k позиций
        {
            t = a[0];
            for (i = 0; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = t;
        }
    }
    else                            // первый элемент нечётный
    {
        k = a[n - 1] % n;
        for (j = 1; j <= k; j++)    // сдвиг вправо на k позиций
        {
            t = a[n - 1];
            for (i = n - 1; i > 0; i--) a[i] = a[i - 1];
            a[0] = t;
        }
    }
}

void shift_array(int n, long a[])
{
    int i, j, k;
    long t;
    if (a[0] % 2 == 0)
    {
        k = a[0] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[0];
            for (i = 0; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = t;
        }
    }
    else
    {
        k = a[n - 1] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[n - 1];
            for (i = n - 1; i > 0; i--) a[i] = a[i - 1];
            a[0] = t;
        }
    }
}

// для float и double берётся целая часть элемента
void shift_array(int n, float a[])
{
    int i, j, k;
    float t;
    if ((int)a[0] % 2 == 0)
    {
        k = (int)a[0] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[0];
            for (i = 0; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = t;
        }
    }
    else
    {
        k = (int)a[n - 1] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[n - 1];
            for (i = n - 1; i > 0; i--) a[i] = a[i - 1];
            a[0] = t;
        }
    }
}

void shift_array(int n, double a[])
{
    int i, j, k;
    double t;
    if ((int)a[0] % 2 == 0)
    {
        k = (int)a[0] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[0];
            for (i = 0; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = t;
        }
    }
    else
    {
        k = (int)a[n - 1] % n;
        for (j = 1; j <= k; j++)
        {
            t = a[n - 1];
            for (i = n - 1; i > 0; i--) a[i] = a[i - 1];
            a[0] = t;
        }
    }
}

int main()
{
    int i;
    int    x[] = { 10, 20, 30, 40, 50, 60 };                  // первый элемент чётный
    long   y[] = { 13L, 44L, 22L, 37L, 3L };                  // первый элемент нечётный
    float  z[] = { 4.5f, 1.5f, 2.5f, 3.5f, 6.5f, 8.5f };      // чётная целая часть
    double w[] = { 9.5, 8.25, 7.5, 6.75, 5.125, 4.0, 3.5 };   // нечётная целая часть

    shift_array(6, x);
    cout << "x:";
    for (i = 0; i < 6; i++) cout << ' ' << x[i];
    cout << endl;

    shift_array(5, y);
    cout << "y:";
    for (i = 0; i < 5; i++) cout << ' ' << y[i];
    cout << endl;

    shift_array(6, z);
    cout << "z:";
    for (i = 0; i < 6; i++) cout << ' ' << z[i];
    cout << endl;

    shift_array(7, w);
    cout << "w:";
    for (i = 0; i < 7; i++) cout << ' ' << w[i];
    cout << endl;
    return 0;
}