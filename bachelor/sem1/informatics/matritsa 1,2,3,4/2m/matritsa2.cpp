#include <iostream>
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int N = 6;
    int A[N] = { 1, 3, 5, 8, 12, 20 };
    bool F = false;
    int i = 0;
    while (i < N - 1 && !F) 
    {
        if (A[i] >= A[i + 1]) 
        {
            F = true;
        }
        else {
            i++;
        }
    }
    if (F == false) 
    {
        cout << "Массив упорядочен по возрастанию." << endl;
    }
    else 
    {
        cout << "Массив НЕ упорядочен по возрастанию." << endl;
    }

    return 0;
}