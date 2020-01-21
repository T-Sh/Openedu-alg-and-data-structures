#include <iostream>#include <fstream>using namespace std;int main() {int n;ifstream in("input.txt");in >> n;

    int *mas = new int[n];
    for (int i = 0; i < n; i++) {
        in >> mas[i];
    }
    in.close();

    ofstream out("output.txt");

    for (int j = 1; j < n; j++) {

        int i = j-1;
        int pos = j;

        while (i >= 0 && mas[i] > mas[i+1]) {
            swap(mas[i], mas[i+1]);

                        out << "Swap elements at indices "
                            << i + 1 << " and " << pos + 1 << ".\n";


            pos = i;
            i--;
        }
    }

    out << "No more swaps needed.\n";

    for (int i = 0; i < n; i++) {
        out << mas[i] << " ";
    }
    out.close();

    delete [] mas;

    return 0;
}