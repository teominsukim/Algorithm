#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string order;

void solve(){
  int n,l;
  cin >> l >> n;
  vector<int> day(n);

  for(int &it : day) cin >> it;


  //min 구하기 
  int min_time = 0;
  for(int i =0; i < n; i++){
    if(min_time < min(l-day[i],day[i]))
       min_time = min(l-day[i],day[i]);
    
  }

  // max 구하기 
  int max_time = 0;
  for(int i =0; i < n; i++){
    if(max_time < max(l-day[i],day[i]))
       max_time = max(l-day[i],day[i]);
    
  }

  // 애드혹이 무엇인지 부터 파악을 해야 할것 같은데 
  
  cout << min_time <<" " << max_time <<endl;

}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
      solve();
    }
}