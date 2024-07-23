#include <iostream>
#include <queue>
using namespace std;

int n,k;
int visited[200001] = {0};
int i = 0;
queue<int> q;

int dfs(int line){

  int count = 0;

  int s = q.size();

  for(int j = 0; j < s; j++){
    int t = q.front();
    if( t == k )
      count++;
    q.pop();
    //printf("%d ",t);

    if(t*2 <= 100000 && t*2 >= 0 && (visited[t*2] == 0 || visited[t*2] == line)){
     q.push(t*2);
     visited[t*2] = line;
     //if(t*2 == k) count++;
    }
    if(t+1 <= 100000 && t+1 >= 0 && (visited[t+1] == 0 || visited[t+1] == line)){
      q.push(t+1);
      visited[t+1] = line;
      //if(t+1 == k) count++;
    }
    if(t-1 <= 100000 && t-1 >= 0 && (visited[t-1] == 0 || visited[t-1] == line)){
      q.push(t-1);
      visited[t-1] = line;
      //if(t-1 == k) count++;
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
    printf("%d\n%d",0,1);
    return 0;
  }

  q.push(n*2);
  visited[n*2] = 1;
  q.push(n+1);
  visited[n+1] = 1;
  if (n-1 >=0){
   q.push(n-1);
   visited[n-1] = 1;
  }

  int a;
  while(1){
    i++;
    a = dfs(i);
    if(a != -1)
      break;
  }

  printf("%d\n%d",i,a);

}