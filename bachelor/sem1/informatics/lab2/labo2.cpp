#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    const int N = 10;       // количество членов ряда
    double a = 1.0;         // a1 = 1!/1^sqrt(1) = 1
    double s = 0.0;         // сумма ряда (в начале она равна 0)
    double d = 0.0;    // контрольная сумма (по общей формуле) 
    double fact = 1.0; //текущее значение n!. Для n = 0 равно 1.

    cout << fixed << setprecision(6);
    for (int n = 1; n <= N; n++)
    {
        s += a; // Добавляем текущий член ряда к сумме (s = s + a)
        fact *= n;
        d += fact / pow(n, sqrt((double)n));
        cout << "n=" << setw(2) << n << "  a_n=" << setw(14) << a << "  S=" << setw(14) << s << endl;
        // рекуррентная формула: a(n+1) = a(n) * (n+1) * n^sqrt(n) / (n+1)^sqrt(n+1)
        a = a * (n + 1) * pow(n, sqrt((double)n)) / pow(n + 1, sqrt((double)(n + 1)));
    }
    cout << "\nСумма " << N << " членов ряда S = " << s << endl;
    cout << "Контроль по общей формуле  S = " << d << endl;
    return 0;
}