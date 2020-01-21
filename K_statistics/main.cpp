#include <iostream>
#include <fstream>

using namespace std;

int n, k1, k2;

void quick_sort(int *mas, int left, int right) {
    int i = left;
    int j = right;
    int key = mas[(left+right)/2];
    do {
        while (mas[i] < key)
            i++;
        while (mas[j] > key)
            j--;
        if (i <= j) {
            swap(mas[i], mas[j]);
            i++;
            j--;
        }

    } while (i <= j);

    if (k2 < j) {
        if (left < j)
            quick_sort(mas, left, j);
    }
    else if (k1 > i) {
        if (i < right)
            quick_sort(mas, i, right);
    }
    else {
        if (left < j)
            quick_sort(mas, left, j);
        if (i < right)
            quick_sort(mas, i, right);
    }
}

int main() {
    ifstream in("input.txt");
    in >> n >> k1 >> k2;
    int A, B, C, a1, a2;
    in >> A >> B >> C >> a1 >> a2;
    in.close();

    int *mas = new int[n];

    mas[0] = a1;
    mas[1] = a2;

    for (int i = 2; i < n; i++) {
        mas[i] = A*mas[i-2] + B*mas[i-1] + C;
    }

    quick_sort(mas, 0, n-1);

    ofstream out("output.txt");
    for (int i = k1-1; i < k2; i++) {
        out << mas[i] << " ";
    }

    out.close();

    return 0;
}