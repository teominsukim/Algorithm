#include <iostream>
#include <vector>

using namespace std;

int dx[3] = {1, 0, 0};
int dy[3] = {2, 2, 1};

int n;
int home[1000][3];
int dp[1000][3];
int MIN = 1000000;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> home[i][j];
        }
    }

    for(int k = 0; k < 3; k++){
        for(int i=0; i < 3; i++)
            dp[0][i] = 99999999;
        dp[0][k] = home[0][k];

        for(int i=1; i < n; i++){
            for(int j = 0; j < 3; j++){
            int k =  dp[i-1][dx[j]] < dp[i-1][dy[j]] ? dp[i-1][dx[j]] : dp[i-1][dy[j]];
            dp[i][j] = home[i][j] + k;
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i < 3; i++){
            if(i != k && MIN > dp[n-1][i]){
                MIN = dp[n-1][i];
            }
        }
    }

    cout << MIN;
}