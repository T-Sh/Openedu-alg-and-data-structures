#include <fstream>

using namespace std;

int digit(int n, int k, int step, int M) {
    return (n >>(step * k) & (M - 1)); }

void radixsort(int* left, int* right) {
    int step = 8;
    int k = (32 + step - 1) / step;
    int M = 1 << step;
    int size = right - left;
    int* b = new int[size];
    int* c = new int[M];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < M; j++)
            c[j] = 0;
        for (int* j = left; j < right; j++)
            c[digit(*j, i, step, M)]++;
        for (int j = 1; j < M; j++)
            c[j] += c[j - 1];
        for (int* j = right - 1; j >= left; j--)
            b[--c[digit(*j, i, step, M)]] = *j;
        int cur = 0;
        for (int* j = left; j < right; j++)
            *j = b[cur++];
    }

    delete [] b; delete [] c; }

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    unsigned short n, m;

    long long sum=0;

    in >> n >> m;
    auto *a = new unsigned short[n];
    auto *b = new unsigned short[m];
    for (int i = 0; i < n; i++) {
        in >> a[i];
    }
    for (int i = 0; i < m; i++) {
        in >> b[i];
    }

    in.close();

    int *c = new int[m*n];
    unsigned int count = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            c[count] = a[i] * b[k];
            count++;
        }
    }
    radixsort(c, c+n * m);
    for (int i = 0; i < n*m; i += 10) {
        sum += c[i];
    }

    out << sum;
    out.close();
}
