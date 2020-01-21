#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream in("input.txt");

    int n;
    in >> n;
    in.close();

    int *mas = new int[n];

    for (int i = 0; i < n; i++) {
        mas[i] = -1;
    }

    if (n == 1)
        mas[0] = 1;
    else if (n == 2)
        (mas[0] = 1), (mas[1] = 2);
    else if (n == 3)
        (mas[0] = 1), (mas[1] = 3), (mas[2] = 2);
    else
    {
        mas[1] = 1; mas[2] = 3;
        for (int i = 4; i <= n; i++) {
            if ((i % 2) == 0)
                mas[i - 1] = mas[(i / 2) - 1];
            else {
                mas[i - 1] = mas[i / 2];
                mas[i / 2] = i;
            }
        }
        for (int i = 0; i < (n / 2); i++)
            mas[i] = i + i + 2;
    }

    ofstream out("output.txt");

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

    out.close();

    return 0;
}