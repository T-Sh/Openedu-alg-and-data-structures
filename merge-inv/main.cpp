#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ofstream out;
int n;

unsigned long long inv = 0;

void merge(int *mas, int l, int r, int m) {
    int i = l;
    int j = m+1;
    int *temp = new int[r+1];
    int pos = -1;
    for (int step = 0; step < r - l + 1; step++) {
        if ((j > r) || ((i <= m) && (mas[i] <= mas[j]))) {
            if (pos >= 0 && step > i - l && mas[i] > temp[pos]) {
                inv += step - i + l;
                //cout << "YES " << step << " - " << i << " + " << l << "  = " << step - i + l << "\n";
            }
            temp[step] = mas[i];
            i++;
        } else {
            temp[step] = mas[j];
            pos = step;
            j++;
        }

    }

    for (int step = 0; step < r - l + 1; step++) {
        mas[l + step] = temp[step];
    }

    /*for (int i = l; i < r+1; i++)
        cout << mas[i] << " ";
    cout << "\n inv = " << inv << "\n";*/

    delete [] temp;
}

void mergeSort(int *mas, int l, int r) {
    if (l == r)
        return;

    if (r - l == 1) {
        if (mas[l] > mas[r]) {
            swap(mas[l], mas[r]);
            inv++;
            /*for (int i = l; i < r+1; i++)
                cout << mas[i] << " ";
            cout << "\n inv = " << inv << "\n";*/
        }
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

    out << inv;

    out.close();

    /*for (int i = 0; i < n; i++)
        cout << mas[i] << " ";*/

    return 0;
}