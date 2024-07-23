#include <iostream>
#include <queue>
using namespace std;

int n,k;
int visited[200001];
queue<int> q;

int dfs(){

  int count = 0;

  int s = q.size();

  for(int i = 0; i < s; i++){
    int t = q.front();
    q.pop();
    if(t == k)
      count++;
    if(t*2 <= 200000 && visited[t*2] == 0){
     q.push(t*2);
     visited[t*2] = 1;
    }
    if(t+1 <= 200000 && visited[t+1] == 0){
      q.push(t+1);
      visited[t+1] = 1;
    }
    if(t-1 >= 0 && visited[t-1] == 0){
      q.push(t-1);
      visited[t-1] = 1;
    }
  }

  if(count == 0)
    return -1;
  else
    return count;

}

int main(){
  cin >> n >> k;

  if(n == k){
    printf("%d",0);
    return 0;
  }

  if(n*2 <= 100000){
    q.push(n*2);
    visited[n*2] = 1;
  }
  q.push(n+1);
  visited[n+1] = 1;
  if(n-1 >= 0){
    q.push(n-1);
    visited[n-1] = 1;
  }

  int a;
  int i = 0;
  while(1){
    i++;
    a = dfs();
    if(a != -1)
      break;
  }

  printf("%d",i);

}