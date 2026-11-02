#include <iostream>
#include <clocale>
using namespace std;
int main() {
    setlocale (LC_ALL, "Russian");
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS] = 
    {
        {3, 5, 2},
        {7, 14, 8},
        {9, 4, 11}
    };
    int maxValue = matrix[0][0];
    int maxRow = 0;
    int maxCol = 0;
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (matrix[i][j] > maxValue) 
            {
                maxValue = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    cout << "Максимальный элемент: " << maxValue << std::endl;
    cout << "Индексы: [" << maxRow << "][" << maxCol << "]" << std::endl;
    return 0;
}

