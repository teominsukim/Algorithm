#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> battery(n);
    vector<int> camul(n);
    for(int &it : battery)cin >> it;
    // 투포인터로 풀이하면 될 것 같은데 - 어림도 없죠
    // 방향을 두개로 해야될 것 같은데?
    int result = -1000000;
    int Max = battery[0];
    for(int i = 1; i < n; i++){
      Max -= k;

      if(result < Max - battery[i])
        result = Max - battery[i];
      
      Max = max(Max,battery[i]);
    }
    Max = battery[n-1];
    for(int i = n-2; i > -1; i--){
      Max -= k;
      
      if(result < Max - battery[i])
        result = Max - battery[i];

      Max = max(Max,battery[i]);
    }
    cout << result;
    return 0;
    
}