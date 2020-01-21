#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;

ofstream out;

void merge(int *mas, int l, int r, int m) {
    int i = l;
    int j = m+1;
    int *temp = new int[r+1];
    for (int step = 0; step < r - l + 1; step++) {
        if ((j > r) || ((i <= m) && (mas[i] < mas[j]))) {
            temp[step] = mas[i];
            i++;
        } else {
            temp[step] = mas[j];
            j++;
        }
    }

    for (int step = 0; step < r - l + 1; step++) {
        mas[l + step] = temp[step];
    }

    out << l+1 << " " << r+1 << " "
         << mas[l] << " " << mas[r] << "\n";

    delete [] temp;
}

void mergeSort(int *mas, int l, int r) {
    if (l >= r)
        return;

    if (r - l == 1) {
        if (mas[l] > mas[r]) {
            swap(mas[l], mas[r]);
        }
        out << l+1 << " " << r+1 << " "
             << mas[l] << " " << mas[r] << "\n";
        return;
    }

    int m = (l + r) / 2;
    mergeSort(mas, l, m);
    mergeSort(mas, m+1, r);
    merge(mas, l, r, m);
}


int main() {
    ifstream in("input.txt");

    in >> n;
    auto *mas = new int[n];

    for(int i = 0; i < n; i++) {
        in >> mas[i];
    }

    in.close();

    out.open("output.txt");

    mergeSort(mas, 0, n-1);

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

    out.close();

    return 0;
}