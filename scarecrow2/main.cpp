#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int n, k;

    ifstream in("input.txt");
    in >> n >> k;
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
        in >> mas[i];
    in.close();

    ofstream out("output.txt");
    if (k == 1) {
        out << "YES";
        out.close();
        return 0;
    }

    int t = 0;
    while (t < k) {
        if (mas[t] > mas[t+k]) {
            swap(mas[t], mas[t+k]);
        }
        t++;
    }

    for (int i = k; i < n; i++) {

        int j = i - k;
        while (j >= 0 && mas[i] < mas[j]) {
            swap(mas[i], mas[j]);
            j -= k;
        }
    }

    int i = 1;
    int j = n-1;
    while (i < j) {
        if (mas[i] < mas[i-1] || mas[j] < mas[j-1]) {
            out << "NO";
            out.close();
            delete [] mas;
            return 0;
        }
        i++;
        j--;
    }

    out << "YES";
    out.close();
    delete [] mas;
    return 0;
}