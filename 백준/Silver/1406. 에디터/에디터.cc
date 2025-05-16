#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// 아니 이거 스택으로 푸는 문제임 
// 문자열 버퍼 연관되는 순간 복잡해지니까 자제하고

int main() {
    int n;
    string s;
    cin >> s;
    cin >> n;

    // 커서 왼쪽의 문자열과 오른쪽의 문자열을 나눈다 
    stack<char> left, right;

    for(int i = 0; i < s.size(); i++){
        left.push(s[i]);
    }

    while(n--) {
        string cmd;
        cin >> cmd;

        if(cmd == "P") {
            char ch;
            cin >> ch;
            left.push(ch);
        } else if(cmd == "L") {
            if(!left.empty()){
                right.push(left.top());
                left.pop();
            }
        } else if(cmd == "D") {
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
        } else if(cmd == "B") {
            if(!left.empty()) left.pop();
        }
    }

    vector<char> a;
    vector<char> b;
    int aa = left.size();
    int bb = right.size();
    for(int i = 0; i < aa; i++){
        a.push_back(left.top());
        left.pop();
    }
    for(int i = 0; i < bb; i++){
        b.push_back(right.top());
        right.pop();
    }
    reverse(a.begin(),a.end());
    for(int i = 0; i < aa; i++) cout << a[i];
    for(int i = 0; i < bb; i++) cout << b[i];


}