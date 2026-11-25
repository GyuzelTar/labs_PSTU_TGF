#include <iostream>
#include <cstring>
using namespace std;

// Создаём массив из n строк и вводим их с клавиатуры
char** make_strings(int n)
{
    char** a = new char* [n];          // массив из n указателей
    char s[100];                      // сюда вводим одну строку
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[i] = new char[strlen(s) + 1];   // выделяем память под строку
        strcpy(a[i], s);                  // копируем строку в память
    }
    return a;
}

// Печатаем n строк
void print_strings(char** a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
}

// Удаляем одинаковые строки. Возвращаем новое количество строк
int remove_same(char** a, int n)
{
    int i = 1;
    while (i < n)
    {
        int same = 0;                     // 1, если такая строка уже была
        for (int j = 0; j < i; j++)
            if (strcmp(a[i], a[j]) == 0)
                same = 1;

        if (same == 1)
        {
            delete[] a[i];                // освобождаем память строки
            for (int j = i; j < n - 1; j++)
                a[j] = a[j + 1];          // сдвигаем остальные строки влево
            n--;                          // строк стало меньше
        }
        else
            i++;                          // идём к следующей строке
    }
    return n;
}

// Удаляем k последних строк. Возвращаем новое количество строк
int remove_last(char** a, int n, int k)
{
    if (k > n)
        k = n;
    for (int i = n - k; i < n; i++)
        delete[] a[i];                    // освобождаем последние строки
    return n - k;
}

// Удаляем весь массив
void delete_strings(char** a, int n)
{
    for (int i = 0; i < n; i++)
        delete[] a[i];                    // сначала каждую строку
    delete[] a;                           // потом массив указателей
}

int main()
{
    int n, k;

    // Задача 1
    cout << "Задача 1. Введите количество строк: ";
    cin >> n;
    cout << "Введите строки:" << endl;
    char** a = make_strings(n);

    n = remove_same(a, n);
    cout << "Без одинаковых строк:" << endl;
    print_strings(a, n);
    delete_strings(a, n);

    // Задача 2
    cout << "Задача 2. Введите количество строк: ";
    cin >> n;
    cout << "Введите строки:" << endl;
    char** b = make_strings(n);

    cout << "Сколько последних строк удалить? ";
    cin >> k;
    n = remove_last(b, n, k);
    cout << "Результат:" << endl;
    print_strings(b, n);
    delete_strings(b, n);

    return 0;
}