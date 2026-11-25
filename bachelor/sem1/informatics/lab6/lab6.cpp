#define _CRT_SECURE_NO_WARNINGS // Отключает ошибки безопасности в Visual Studio (для gets и strcpy)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    // 1. База данных на двумерных символьных массивах
    const int DB_SIZE = 7;
    const int MAX_WORD = 50;

    char eng[DB_SIZE][MAX_WORD] = { "THIS", "IS", "A", "TABLE", "BOOK", "CAT", "BIG" };
    char rus[DB_SIZE][MAX_WORD] = { "ЭТО", "", "", "СТОЛ", "КНИГА", "КОТ", "БОЛЬШОЙ" };

    // 2. Ввод строки с помощью функции gets()
    char s[256];
    cout << "Введите предложение на английском языке:\n";
    gets(s); // Примечание: в новых стандартах C++14/17 вместо gets(s) используют gets_s(s)

    char result[512] = "";      // Результирующая строка
    char currentWord[MAX_WORD]; // Буфер для текущего слова
    int wordIdx = 0;            // Индекс текущей буквы в слове

    int len = strlen(s);

    // 3. Посимвольная обработка строки (включая завершающий ноль '\0' в конце)
    for (int i = 0; i <= len; i++) {
        // Если текущий символ не разделитель и не конец строки — собираем слово
        if (s[i] != '_' && s[i] != '\0') {
            currentWord[wordIdx] = s[i];
            wordIdx++;
        }
        else {
            // Если слово не пустое, завершаем его нуль-терминатором и ищем в базе
            if (wordIdx > 0) {
                currentWord[wordIdx] = '\0';

                char translated[MAX_WORD];
                strcpy(translated, currentWord); // По умолчанию оставляем исходное слово

                // Поиск слова в базе данных
                for (int j = 0; j < DB_SIZE; j++) {
                    if (strcmp(eng[j], currentWord) == 0) {
                        strcpy(translated, rus[j]); // Копируем найденный перевод
                        break;
                    }
                }

                // Если перевод не пустой (не "IS" и не "A"), добавляем в результат
                if (strlen(translated) > 0) {
                    if (strlen(result) > 0) {
                        strcat(result, "_"); // Добавляем разделитель, если результат не пуст
                    }
                    strcat(result, translated);
                }

                wordIdx = 0; // Сбрасываем индекс для следующего слова
            }
        }
    }

    // 4. Вывод результата
    cout << "Перевод:\n" << result << endl;

    return 0;
}
этот код подойдёт ?