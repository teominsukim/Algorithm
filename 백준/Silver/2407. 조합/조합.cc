#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

// 조합 연산식을 활용하는 것 같다 (n r) = (n-1 r-1) + (n-1 r) 이를 배열로 표현해야겠다. 
// string 은 vector<char> 처럼 동작한다 
// reverse 를 또 배워가는군 

string add(string a, string b){
    string res = "";
    int temp = 0;

    while (!a.empty() || !b.empty() || temp) {
        if(!a.empty()) {
            temp += (a.back() - '0');
            a.pop_back();
        }
        if(!b.empty()) {
            temp += (b.back() - '0');
            b.pop_back();
        }
        res += temp % 10 + '0';
        temp /= 10;
    }

    reverse(res.begin(),res.end());
    return res;
    
}

string combination(int n, int m) {
    if(n == 0 || m == 0)
        return "1";
    if(n == m)
        return "1"; 
    return add(combination(n-1,m-1),combination(n-1,m));
}

int main(){
    // dp 를 사용하여 문제를 해결하는 것이다
    int n,m;
    cin >> n >> m;
    
    string dp[101][101];

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= i; j++){
            if(i == j || j == 0 || i == 0){
                dp[i][j] = "1";
            } else {
                dp[i][j] = add(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }

    cout << dp[n][m];
}