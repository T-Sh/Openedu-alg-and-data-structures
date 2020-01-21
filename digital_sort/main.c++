#include <vector>
#include <array>
#include <string>
#include "edx-io.hpp"

using namespace std;

int main() {

    int m, n, k;
    io >> m >> n >> k;

    int c = 26;                      // количество разных значений char
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        io >> strs[i];
    }

    vector<int> imIxs;               // промежуточные индексы для сортировки подсчётом
    vector<array<int, 2>> resIxs;    // индексы в strs, хранящие сортировку; нужен, чтобы не копировать строки каждую итерацию
    bool re = false;                 // второй индекс в массиве resIxs для отделения последовательных итераций цифровой сортировки
    resIxs.resize(m);
    for (int i = 0; i < m; i++)
        resIxs[i][re] = i;

    // цикл цифровой сортировки
    for (int j = n - 1; j >= n - k; j--) {
        // сортировка подсчётом
        imIxs.assign(c, 0);

        for (int i = 0; i < m; i++)
            imIxs[strs[j][resIxs[i][re]] - 'a']++;

        int sum = 0, temp;
        for (int i = 0; i < c; i++) {
            temp = imIxs[i];
            imIxs[i] = sum;
            sum += temp;
        }

        for (int i = 0; i < m; i++)
            resIxs[imIxs[strs[j][resIxs[i][re]] - 'a']++][re ^ 1] = resIxs[i][re];

        re ^= true;
    }
    for (int i = 0; i < m - 1; i++) {
        io << resIxs[i][re] + 1 << ' ';
    }
    io << resIxs[m - 1][re] + 1 << ' ';

    return 0;
}