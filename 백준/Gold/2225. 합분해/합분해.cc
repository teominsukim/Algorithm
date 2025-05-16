#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#define MAX 1000000000

using namespace std;

int main() {
    // 그렇게 하면 안되고 6 을 어떻게 만들수 잇을지 고민해야함 
    // 앞자리가 무엇이 되느냐에 따라서 달라진다. 
    int dp[220][220];

    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++) 
        dp[i][1] = 1;
    for(int j = 0; j <= k; j++) 
        dp[0][j] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MAX;
        }
    }

    cout << dp[n][k];
    return 0;
}