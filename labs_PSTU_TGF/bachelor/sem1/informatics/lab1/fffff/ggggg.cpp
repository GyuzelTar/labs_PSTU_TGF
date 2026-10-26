#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    char symbols[5];

    // Ввод пяти символов
    for (int i = 0; i < 5; i++) {
        setlocale(LC_ALL, "RU");
        cout << "Введите символ " << i + 1 << ": ";
        cin >> symbols[i];
    }

    // Вывод в обратном порядке
    cout << "Символы в обратном порядке: ";
    for (int i = 4; i >= 0; i--) {
        setlocale(LC_ALL, "RU");
        cout << symbols[i] << " ";
    }
    cout << endl;

    return 0;
}