#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n;
    ifstream in("input.txt");
    in >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        in >> mas[i];
    }
    in.close();
    bool check = true;
    for (int j = 0; j < n; j++) {
        if (2 * j + 1 < n) {
            check = (mas[j] <= mas[2 * j + 1]);
            //cout << mas[j] << " " << mas[2*j+1] << "   " << check << "\n";
        }
        if (!check) {
            break;
        }
        if (2 * j + 2 < n) {
            check = (mas[j] <= mas[2 * j + 2]);
            //cout << mas[j] << " " << mas[2*j+2] << "   " << check << "\n";
        }
        //cout << mas[j] << " " << mas[2*j+1] << " " << mas[2*j+2] << "\n";
        if (!check) {
            break;
        }
    }
    ofstream out("output.txt");
    if (check) {
        out << "YES";
    } else {
        out << "NO";
    }
    out.close();

    return 0;
}