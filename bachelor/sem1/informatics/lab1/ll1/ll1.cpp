#include <iostream>
#include <iomanip>
using namespace std;
void calcfloat()
{
    setlocale(LC_ALL, "RU");
    float af, bf, cf, df, ef, ff, gf;
    af = 1000;
    bf = 0.0001;
    cf = (af + bf) * (af + bf) * (af + bf); //вычеслим первую часть числителя
    df = (af * af * af) + (3 * (af * af) * bf); //вычеслим вторую часть числителя
    ef = cf - df; //вычеслим чеслитель 
    ff = (3 * af * (bf * bf)) + (bf * bf * bf); //вычеслим знаменатель
    gf = ef / ff; //вычеслим полное выражение
    cout << "float:  числитель = " << ef
        << ", знаменатель = " << ff
        << ", результат = " << gf << endl; // выводим значения числителя, знаменателя и результат выражения
}
void calcdouble()
{
    setlocale(LC_ALL, "RU");
    double a, b, c, d, e, f, g;
    a = 1000;
    b = 0.0001;
    c = (a + b) * (a + b) * (a + b); //вычеслим первую часть числителя
    d = (a * a * a) + (3 * (a * a) * b); //вычеслим вторую часть числителя
    e = c - d;//вычеслим чеслитель
    f = (3 * a * (b * b)) + (b * b * b); //вычеслим знаменатель
    g = e / f; //вычеслим полное выражение
    cout << "double:  числитель = " << e
        << ", знаменатель = " << f
        << ", результат = " << g << endl; // выводим значения числителя, знаменателя и результат выражения
}
int main()
{
    setlocale(LC_ALL, "RU");
    cout << fixed << setprecision(10);
    calcfloat();
    calcdouble();
    return 0;
}