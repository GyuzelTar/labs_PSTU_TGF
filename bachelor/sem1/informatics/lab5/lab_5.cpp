#include <iostream>
#include <clocale>
using namespace std;
const int N = 6;
void Matrix(const int a[], int ad[][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
			ad[j][i] = 1;
		int pe = a[i] - (N - 1);
		if (pe == 0)
		{
			ad[0][i] = 2;
			pe = -1;
		}

		ad[N - 1][i] = pe;
	}
}
int main()
{
	setlocale(LC_ALL, "RU");
	int a[N];
	int ad[N][N];
	cout << "Введите " << N << " целых чисел:\n";
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	Matrix(a, ad);
	cout << "Полученная матрица:\n";
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < N; ++i)
			cout << ad[j][i] << '\t';
		cout << '\n';
	}
}