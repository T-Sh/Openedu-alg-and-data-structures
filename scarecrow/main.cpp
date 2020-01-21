#include <iostream>
#include <fstream>
//#include <ctime>

using namespace std;

int n, k;
bool check(const int *mas) {
    int i = 1;
    int j = n-1;
    while (i < j) {
        if (mas[i] < mas[i-1] || mas[j] < mas[j-1])
            return false;
        i++;
        j--;
    }
    return true;
}


void quick_sort(int *mas, int left, int right) {
    int middle = left + ((right - left) / k / 2) * k;
    int i = left;
    int j = right;
    int key = mas[middle];
    //cout << i << " " << j << "   " << middle << "\n";
    do {
        while (i < right && mas[i] < key)
            i += k;
        while (j > left && mas[j] > key) {
            j -= k;
            //cout << j << " " << mas[j] << "\n";
        }
        if (i <= j) {
            swap(mas[i], mas[j]);
            //cout << "swap: " << i << " " << j << "\n";
            i += k;
            j -= k;
            /*for (int m = 0; m < n; m++)
                cout << mas[m] << " ";
            cout << "\n";*/
        }
        //cout << i << " " << j << "\n";

    } while (i <= j);

    //cout << i << " " << j << "   " << left << " " << right << "\n";


    if (left < j) {
        //cout << "left\n";
        quick_sort(mas, left, j);
    }
    if (i < right) {
        //cout << "right\n";
        quick_sort(mas, i, right);
    }

}

void sort(int *mas) {

    for(int i = 0; i <= k; i++) {
        //cout << i << " " << n-1 - (n-1-i)%k << "\n";
        quick_sort(mas, i, n - 1 - (n - 1 - i) % k);
    }
}

int main() {

    //srand(time(0));

    ifstream in("input.txt");
    in >> n >> k;
    int *mas = new int[n];
    for (int i = 0; i < n; i++)
        in >> mas[i];
    in.close();

    /*k = 5;
    n = 1128;
    int *mas = new int[n];
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 10 + 1;
        cout << mas[i] << " ";
    }
    cout << "\n\n";*/

    ofstream out("output.txt");
    if (k == 1) {
        out << "YES";
        out.close();
        return 0;
    }

    sort(mas);

    out << (check(mas) ? "YES" : "NO");

    out.close();
    delete [] mas;
    return 0;
}