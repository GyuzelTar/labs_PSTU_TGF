#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int matrix[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = rand() % 101 - 50;
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}
