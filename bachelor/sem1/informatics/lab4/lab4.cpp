#include <iostream>
#include <clocale>
using namespace std;
const int N = 100;

int a[N];      /* значения элементов кольца            */
int nxt[N];    /* индекс правого соседа (вперед)       */
int prv[N];    /* индекс левого соседа (назад)         */

/* печать кольца, начиная с элемента start, в направлении dir */
/* dir = 1 - вправо, dir = -1 - влево; печатается n элементов  */
void print_ring(int start, int n, int dir)
{
    setlocale(LC_ALL, "Russian");
    int p = start;
    for (int i = 0; i < n; i++) {
        cout << a[p] << " ";
        p = (dir == 1) ? nxt[p] : prv[p];
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k, max, head, p, cnt;

    cout << "Введите длину кольца n (1.." << N << "): ";
    if (!(cin >> n) || n < 1 || n > N) {
        cout << "Неверная длина\n";
        return 1;
    }

    cout << "Введите " << n << " элементов: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /* построение двунаправленного кольца на массиве */
    for (int i = 0; i < n; i++) {
        nxt[i] = (i + 1) % n;
        prv[i] = (i - 1 + n) % n;
    }
    head = 0;

    cout << "Введите номер элемента K (1.." << n << "): ";
    if (!(cin >> k) || k < 1 || k > n) {
        cout << "Неверное K\n";
        return 1;
    }

    /* п. 2: вывод от K-го элемента по кольцу влево */
    cout << "Кольцо от K-го влево: ";
    print_ring(k - 1, n, -1);

    /* п. 3: удаление всех элементов, равных максимуму */
    max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    cnt = n;
    p = head;
    for (int i = 0; i < n && cnt > 0; i++) {
        int next_p = nxt[p];
        if (a[p] == max) {
            if (cnt == 1) {          /* удаляется последний элемент */
                cnt = 0;
            }
            else {
                nxt[prv[p]] = nxt[p];
                prv[nxt[p]] = prv[p];
                if (p == head) {
                    head = nxt[p];
                }
                cnt--;
            }
        }
        p = next_p;
    }
    cout << "Максимальное значение " << max << ", удалено элементов: " << (n - cnt) << "\n";

    if (cnt == 0) {
        cout << "Кольцо пусто\n";
        return 0;
    }

    /* п. 4: K теперь - номер в новом кольце (от головы) */
    k = (k - 1) % cnt;
    p = head;
    for (int i = 0; i < k; i++) {
        p = nxt[p];
    }
    cout << "Кольцо от K-го вправо: ";
    print_ring(p, cnt, 1);

    return 0;
}
