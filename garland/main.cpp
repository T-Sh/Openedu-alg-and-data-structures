#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    int n;
    in >> n;
    auto *mas = new double[n];
    in >> mas[0];
    in.close();

    const double eps = 1e-10;
    double B = 0.0;
    double A = mas[0];

    while (A - B > eps) {
        mas[1] = (B + A)/2;
        int i = 2;
        do {
            double temp = 2.0*mas[i-1] - mas[i-2]+2.0;
            mas[i] = temp;
            i++;
        } while (mas[i-1] >= eps && i < n);

        if (i == n && mas[i-1] >= 0) {
            A = mas[1];
        } else {
            B = mas[1];
        }
    }

    for (int j = 0; j < n; ++j) {
        cout << mas[j] << " ";
    }

    ofstream out("output.txt");
    out << mas[n-1];
    out.close();
    return 0;
}