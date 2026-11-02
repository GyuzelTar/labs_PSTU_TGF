#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const double eps = 0.0001;   // заданная точность
    const int N = 15;            // заданное число членов ряда
    const int k = 10;            // число шагов
    const double a = 0.1, b = 1.0;
    double h = (b - a) / k;

    cout << "Вычисление функции" << endl;
    cout << fixed;
    for (int i = 0; i <= k; i++)              // внешний цикл по x
    {
        double x = a + i * h;
        double t = (2 * x) * (2 * x);         // (2x)^2

        // сумма для заданного n (арифметический цикл)
        double an = -t / 2;                   // a1
        double sn = an;
        for (int n = 1; n < N; n++)
        {
            an = -an * t / ((2 * n + 1) * (2 * n + 2));   // a(n+1)
            sn += an;
        }

        // сумма для заданной точности (итерационный цикл)
        an = -t / 2;
        double se = an;
        int n = 1;
        while (fabs(an) >= eps)
        {
            an = -an * t / ((2 * n + 1) * (2 * n + 2));
            se += an;
            n++;
        }

        double y = 2 * (cos(x) * cos(x) - 1); // точное значение

        cout << setprecision(4) << "X=" << x
            << setprecision(6) << "  SN=" << sn
            << "  SE=" << se << "  Y=" << y << endl;
    }
    return 0;
}