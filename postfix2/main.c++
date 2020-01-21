#include <fstream>
#include <stack>

using namespace std;

int sign(const string &str) {
    if (str == "+")
        return 1;
    if (str == "-")
        return 2;
    return 3;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    stack<int> s;
    for (int i = 0 ; i < n; i++) {
        string str;
        in >> str;
        if (str != "+" && str != "-" && str != "*") {
            s.push(stoi(str));
        } else {
            int temp = sign(str);
            switch (temp) {
                case 1: {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    s.push(right + left);
                    break;
                }
                case 2: {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    s.push(left - right);
                    break;
                }
                case 3: {
                    int right = s.top();
                    s.pop();
                    int left = s.top();
                    s.pop();
                    s.push(right * left);
                    break;
                }
                default:break;
            }
        }
    }
    in.close();
    out << s.top();
    out.close();
    return 0;
}