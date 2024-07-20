#include <stdio.h>
#define MAX_SIZE 20

int graph[MAX_SIZE][MAX_SIZE];

int count = 0;
int front =-1, rear = -1;
int n;

int dfs(int row,int col,int mode){

  if(graph[row][col] == 1)
    return 0;

  if(mode == 3)
    if(graph[row-1][col] == 1 || graph[row][col-1] == 1)
      return 0;

  if(row == n && col == n){
    count++;
    //printf("!\n");
    return 0;
  }

  if(row >  n|| col > n)
    return 0;

  //printf("%d %d\n",row,col);


  if(mode == 1){
    dfs(row,col+1,1);
    dfs(row+1,col+1,3);
  }
  else if(mode == 2){
    dfs(row+1,col,2);
    dfs(row+1,col+1,3);
  }
  else if(mode == 3){
    dfs(row+1,col+1,3);
    dfs(row,col+1,1);
    dfs(row+1,col,2);
  }

  return 0;
  
}
//이게 이게 dfs구현 하는 것

int main(){

  scanf("%d",&n);
  for(int i=1; i<=n; ++i)
    for(int j = 1; j<=n; j++)
      scanf("%d",&graph[i][j]);

  dfs(1,2,1);

  printf("%d",count);

  return 0;
}