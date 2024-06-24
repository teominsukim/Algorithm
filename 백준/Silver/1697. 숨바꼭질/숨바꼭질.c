#include <stdio.h>
#define MAX 100000

int graph[MAX+1][3];
int visit[MAX+1] = {0,};
int queue[MAX+1] = {0,};
int time[MAX+1] = {0,};
int front = 0;
int rear = -1;

int bfs(int n, int k){

  if(n == k)
    return 0;

  for(int i = 0; i <= MAX; i++){
    graph[i][0] = i-1;
    graph[i][1] = i+1;
    graph[i][2] = i*2;
  }

  int current = n;
  visit[n] = 1;
  queue[++rear] = n;

  while(1){

    current = queue[front++]; // 큐에서 팝하는 동작이다.

    for(int i = 0; i < 3; i++){
      int next = graph[current][i];
      
      if( visit[next] == 0 && next >= 0 && next <= MAX){
        queue[++rear] = next;
        visit[next] = 1;
        time[next] = time[current] + 1;

      }
      if(next == k)
        return time[k];
    }


  }

  return 0;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  printf("%d",bfs(N,K));

}