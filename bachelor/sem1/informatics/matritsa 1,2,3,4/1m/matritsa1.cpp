#include <iostream>
#include <clocale>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int arr[10] = { 5, 9, 2, 4, 2, 9, 7, 2, 6, 3 };
    int size = 10;
    cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    int min_val = arr[0];
    int max_val = arr[0];

    int min_index = 0;
    int max_index = 0;

    int min_count = 1;
    int max_count = 1;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_index = i;
            max_count = 1;
        }
        else if (arr[i] == max_val) {
            max_count++;
        }

        
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_index = i;
            min_count = 1;
        }
        else if (arr[i] == min_val) {
            min_count++; 
        }
    }

    cout << "Максимальный элемент: " << max_val << "\n";
    cout << "Индекс первого максимума: " << max_index << " (Номер: " << max_index + 1 << ")\n";
    cout << "Количество элементов, равных максимуму: " << max_count << "\n\n";

    cout << "Минимальный элемент: " << min_val << "\n";
    cout << "Индекс первого минимума: " << min_index << " (Номер: " << min_index + 1 << ")\n";
    cout << "Количество элементов, равных минимуму: " << min_count << "\n";

    return 0;
}