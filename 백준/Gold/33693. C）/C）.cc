#include <iostream>
#include <string>
#include <vector>

using namespace std;

void uc() {
    int result_n = 0;
    string s;
    cin >> s;

    string result_s = "";
    int depth = 0;

    for (int i = 0; i < s.size(); i++) {
        if (depth == 0) {
            if (s[i] == 'C') {
                depth++;
            } else {
                depth++;
                result_n++;
            }
            result_s += '(';
        } else {
            if (s[i] == 'U') {
                depth--;
                result_s += ')';
                result_n++;
            } else if (s[i] == 'C') {
                if (s.size() - i <= depth) {
                    depth--;
                    result_s += ')';
                    result_n += 2;
                } else {
                    depth++;
                    result_s += '(';
                }
            }
        }
    }

    cout << result_n << '\n' << result_s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        uc();
        cout << '\n';
    }
}
