#include <fstream>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        string str;
        in >> str;
        stack<char> count;

        for (char s : str) {
            //cout << s << "\n";
            if (count.empty() && (s == ']' || s == ')')) {
                count.push(s);
                //cout << "1\n";
                break;
            }
            if (s == '(' || s == '[') {
                count.push(s);
                //cout << "2\n";
            } else {
                if ((count.top() == '(' && s == ')') || (count.top() == '[' && s == ']')) {
                    count.pop();
                    //cout << "3\n";
                } else {
                    //cout << "4\n";
                    break;
                }
            }
        }

        if (count.empty()) {
            out << "YES\n";
        } else {
            out << "NO\n";
        }
    }

    in.close();
    out.close();
    return 0;
}