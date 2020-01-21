#include <stack>
#include <fstream>

using namespace std;

int code(const string &str) {
    if (str == "+")
        return 1;
    if (str == "-")
        return 2;
    return 3;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    stack<int> s;

    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        string symbol;
        in >> symbol;

        if (symbol != "+" && symbol != "-" && symbol != "*") {
            s.push(stoi(symbol));
        } else {
            int c = code(symbol);
            switch (c) {
                case 1: {
                    int left = s.top();
                    s.pop();
                    int right = s.top();
                    s.pop();
                    s.push(left + right);
                    break;
                }
                case 2: {
                    int left = s.top();
                    s.pop();
                    int right = s.top();
                    s.pop();
                    s.push(right - left);
                    break;
                }
                case 3: {
                    int left = s.top();
                    s.pop();
                    int right = s.top();
                    s.pop();
                    s.push(left * right);
                    break;
                }
                default:break;
            }
        }
    }
    out << s.top();

    in.close();
    out.close();
    return 0;
}