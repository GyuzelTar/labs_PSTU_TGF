#include <iostream>
#include <clocale>
using namespace std;

void print_arr(const int* A, const int& N)
{
    setlocale (LC_ALL, "Russian");
    for (int k = 0; k < N; k++)
        cout << A[k] << "\t";
    cout << endl;
}

// Сортировка вставкой
// A - массив, i - индекс в неотсортированной части,
// j - индекс в отсортированной части, Y - переносимый элемент,
// F - флажок "место для Y ещё не найдено"
void insert_sort(int* A, const int& N)
{
    setlocale (LC_ALL, "Russian");
    for (int i = 1; i < N; i++)
    {
        int Y = A[i];
        int j = i - 1;
        bool F = true;
        while (j >= 0 && F)
        {
            if (A[j] > Y)
            {
                A[j + 1] = A[j];
                j--;
            }
            else
                F = false;
        }
        A[j + 1] = Y;
    }
}

// Сортировка выбором
void selection_sort(int* A, const int& N)
{
    setlocale (LC_ALL, "Russian");
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < N; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
        {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

// Сортировка пузырьком (обменом)
void bubble_sort(int* A, const int& N)
{
    setlocale (LC_ALL, "Russian");
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - i - 1; j++)
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
}

int main()
{
    setlocale (LC_ALL, "Russian");
    const int N = 6;
    int base[N] = { 5, 2, 9, 1, 7, 3 };
    int a[N], b[N], c[N];
    for (int k = 0; k < N; k++) a[k] = b[k] = c[k] = base[k];

    cout << "Исходный массив:" << endl;
    print_arr(base, N);

    insert_sort(a, N);
    cout << "Вставка:" << endl;   print_arr(a, N);
    selection_sort(b, N);
    cout << "Выбор:" << endl;     print_arr(b, N);
    bubble_sort(c, N);
    cout << "Пузырёк:" << endl;   print_arr(c, N);
    return 0;
}