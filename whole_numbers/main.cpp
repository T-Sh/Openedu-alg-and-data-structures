#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



void quick_sort(vector<unsigned int> *mas, unsigned int left, unsigned int right) {
    unsigned int i = left;
    unsigned int j = right;
    unsigned int key = mas->at((left+right)/2);
    do {
        while (mas->at(i) < key)
            i++;
        while (mas->at(j) > key)
            j--;
        if (i <= j) {
            swap(mas->at(i), mas->at(j));
            i++;
            j--;
        }

    } while (i <= j);

    if (left < j)
        quick_sort(mas, left, j);
    if (i < right)
        quick_sort(mas, i, right);
}

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    unsigned short n1, n2;

    fin >> n1 >> n2;
    unsigned short *a = new unsigned short[n1];
    unsigned short *b = new unsigned short[n2];
    for (int i = 0; i < n1; i++) {
        fin >> a[i];
    }
    for (int i = 0; i < n2; i++) {
        fin >> b[i];
    }

    fin.close();
    unsigned int *c = new unsigned int[n2*n1];
    unsigned int max = a[0] * b[0];
    unsigned int min = max;
    unsigned int count = 0;
    for (int i = 0; i < n1; i++) {
        for (int k = 0; k < n2; k++) {
            c[count] = a[i] * b[k];
            if (c[count] > max)
                max = c[count];
            if (c[count] < min)
                min = c[count];
            count++;
        }
    }

    delete [] a;
    delete [] b;

    unsigned int pockets = 1500;
    unsigned int d = (max - min + pockets) / pockets;

    //Создание карманов
    auto *poc = new vector< vector<unsigned int> >;
    for (int i = 0; i < pockets; i++) {
        vector<unsigned int> temp;
        poc->push_back(temp);
    }

    for (unsigned int i = 0; i < n1*n2; i++) {
        unsigned int index = ((c[i] - min) / d);
        //cout << index << "\n";
        poc->at(index).push_back(c[i]);
    }

    for (unsigned int i = 0; i < pockets; i++) {
        if (poc->at(i).size() > 2) {
            quick_sort(&(poc->at(i)), 0, (poc->at(i).size() - 1));
        } else if (poc->at(i).size() == 2) {
            if (poc->at(i).at(0) > poc->at(i).at(1)) {
                swap(poc->at(i).at(0), poc->at(i).at(1));
            }
        }
    }

    unsigned int pos = 0;

    unsigned int sum = 0;

    //Подсчет суммы
    for (unsigned int i = 0; i < pockets; i++) {

        for (unsigned int j = 0; j < poc->at(i).size(); j++) {
            if (pos % 10 == 0)
                sum += poc->at(i).at(j);
            pos++;
        }

    }

    fout << sum;
    fout.close();

    delete [] c;

    return 0;
}