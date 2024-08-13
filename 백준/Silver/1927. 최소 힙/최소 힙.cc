#include <iostream>
#include <queue>
using namespace std;

int n;

priority_queue<int, vector<int>> p_q;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i = 0 ; i < n; i ++){
    int temp;
    cin >> temp;
    if (temp == 0){
      if (p_q.empty()){
        cout << 0 << "\n";
      }
      else {
        cout << -1*p_q.top() << "\n";
        p_q.pop();
      }
    }
    else{
      p_q.push(-1*temp);
    }
  }

  return 0;
}