#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

int main(){
  vector<int> numbers(10001,0);
  for(int i = 2; i <= 10000; i++){
    if(numbers[i] == 0){
      for(int j = i+1; j <= 10000; j++){
        if(numbers[j] == 0 && j % i == 0){
          numbers[j] = 1;
        }
      }
    } 
  }
  
  int t;
  cin >> t;
  while (t--)
  {
   int n;
   cin >> n;
   int a,b;
   for(int i = 2; i <= 10000; i++){
      if(numbers[i] == 0 && numbers[n-i] == 0){
        if(i > n-i){
          cout << a << " " << b << endl;
          break;
        }
        a = i;
        b = n - i;
      }
   }
  }
}