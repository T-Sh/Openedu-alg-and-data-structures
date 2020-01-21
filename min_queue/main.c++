#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    stack< pair<int, int> > s1, s2;
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        char sign;
        in >> sign;

        if (sign == '+') {
            int new_element;
            in >> new_element;
            int minima = s1.empty() ? new_element : min (new_element, s1.top().second);
            s1.push (make_pair (new_element, minima));
        }
        else
            if (sign == '-') {
                if (s2.empty())
                    while (!s1.empty()) {
                        int element = s1.top().first;
                        s1.pop();
                        int minima = s2.empty() ? element : min (element, s2.top().second);
                        s2.push (make_pair (element, minima));
                    }
                s2.pop();
            }
            else {
                int current_minimum;
                if (s1.empty() || s2.empty())
                    current_minimum = s1.empty() ? s2.top().second : s1.top().second;
                else
                    current_minimum = min (s1.top().second, s2.top().second);
                out << current_minimum << "\n";
            }
    }

    in.close();
    out.close();
    return 0;
}