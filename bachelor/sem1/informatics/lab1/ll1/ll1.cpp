#include <iostream>
#include <iomanip>
using namespace std; 
void calcfloat()
{
    setlocale(LC_ALL, "RU");
    float af, bf, cf, df, ef;
    af = 1000;
    bf = 0.0001;
    cf = (pow(af + bf, 3) - (pow(af, 3) + 3 * pow(af, 2) * bf)); //вычеслим числитель
    df = (3 * af * pow(bf, 2) + pow(bf, 3)); //вычеслим знаменатель
    ef = cf / df; //вычеслим полное выражение
    cout << "float:  числитель = " << cf
        << ", знаменатель = " << df
        << ", результат = " << ef << endl; // выводим значения числителя, знаменателя и результат выражения
}
void calcdouble()
{
    setlocale(LC_ALL, "RU");
    double ad, bd, cd, dd, ed;
    ad = 1000;
    bd = 0.0001;
    cd = (pow(ad + bd, 3) - (pow(ad, 3) + 3 * pow(ad, 2) * bd)); //вычеслим числитель
    dd = (3 * ad * pow(bd, 2) + pow(bd, 3)); //вычеслим знаменатель
    ed = cd / dd; //вычеслим полное выражение
    cout << "double:  числитель = " << cd
        << ", знаменатель = " << dd
        << ", результат = " << ed << endl; // выводим значения числителя, знаменателя и результат выражения
}
void calcmn()
{
    setlocale(LC_ALL, "RU");
    int n, m, r;

    // 1) n---m  разбирается как (n--) - m
    n = 5; m = 3;
    r = n-- - m;      // берётся старое n (5), вычисляется 5 - 3 = 2, затем n уменьшается до 4
    cout << "1) n---m : результат = " << r
        << ", n = " << n << ", m = " << m << endl;   // 2, n=4, m=3

    // 2) m--<n  разбирается как (m--) < n
    n = 5; m = 3;
    r = m-- < n;      // сравнивается старое m (3) с n (5): 3 < 5 даёт 1, затем m уменьшается до 2
    cout << "2) m--<n : результат = " << r
        << ", n = " << n << ", m = " << m << endl;   // 1, n=5, m=2

    // 3) n++>m  разбирается как (n++) > m
    n = 5; m = 3;
    r = n++ > m;      // сравнивается старое n (5) с m (3): 5 > 3 даёт 1, затем n увеличивается до 6
    cout << "3) n++>m : результат = " << r
        << ", n = " << n << ", m = " << m << endl;   // 1, n=6, m=3
}
int main()
{
    setlocale(LC_ALL, "RU");
    cout << fixed << setprecision(10);
    calcfloat();
    calcdouble();
    calcmn();
    return 0;
}
