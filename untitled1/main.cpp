#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int n;
    ifstream in("input.txt");
    in >> n;

    vector<int> mas;

    int num;

    for (int i = 0; i < n; i++) {
        in >> num;
        mas.push_back(num);
    }
    in.close();

    ofstream out("output.txt");

    int min;
    int pos;

    for (int j = 0; j < n-1; j++) {
        pos = j;
        min = mas[j];
        for (int i = j+1; i < n; i++) {
            if (mas[i] < min) {
                min = mas[i];
                pos = i;
            }
        }
        if (pos != j) {
            swap(mas[j], mas[pos]);
            out << "Swap elements at indices "
                << j + 1 << " and " << pos + 1 << ".\n";
        }
    }

    out << "No more swaps needed.\n";

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }

    out.close();

    return 0;
}
