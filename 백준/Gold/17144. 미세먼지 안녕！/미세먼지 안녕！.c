#include <stdio.h>

int r,c,t;
int row_1=0,row_2=0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int graph_second[51][51];
int graph_temp[51][51];

void diffusion_1(){

  for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
      graph_second[i][j] = 0;

  for(int i = 1;i<=r;i++)
    for(int j = 1;j<=c;j++)
      {
        if(graph_temp[i][j] == -1)
          continue;
        int d = graph_temp[i][j] / 5;
        for(int k=0; k < 4; k++)
          if(i+dx[k] >= 1 && i+dx[k] <= r && j+dy[k] >= 1 && j+dy[k] <= c && graph_temp[i+dx[k]][j+dy[k]] != -1){
            graph_second[i+dx[k]][j+dy[k]] += d;
            graph_temp[i][j] -= d;
          }
        graph_second[i][j] += graph_temp[i][j];
      }

}

void diffusion_2(){ 

  for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
      graph_temp[i][j] = 0;

  for(int i = 1;i<=r;i++)
    for(int j = 1;j<=c;j++)
      {
        if(graph_second[i][j] == -1)
          continue;
        int d = graph_second[i][j] / 5;
        for(int k=0; k < 4; k++)
          if(i+dx[k] >= 1 && i+dx[k] <= r && j+dy[k] >= 1 && j+dy[k] <= c && graph_temp[i+dx[k]][j+dy[k]] != -1){
            graph_temp[i+dx[k]][j+dy[k]] += d;
            graph_second[i][j] -= d;
          }
        graph_temp[i][j] += graph_second[i][j];
      }

}

int aircon(){

  diffusion_1();

  for(int i = 1;i<=r;i++){
    for(int j = 1;j<=c;j++){
      if(i != row_1 && i != row_2 && i != 1 && i != r && j != 1 && j != c)
      graph_temp[i][j] = graph_second[i][j];
      else
        graph_temp[i][j] = 0;
    }
  }

  graph_temp[row_1][1] = -1;
  graph_temp[row_2][1] = -1;

  for(int i = 2;i<c;i++)
    graph_temp[row_1][i+1] = graph_second[row_1][i];
  for(int i = row_1;i>1;i--)
    graph_temp[i-1][c] = graph_second[i][c];
  for(int i = 1;i<=c;i++)
    graph_temp[1][i-1] = graph_second[1][i];
  for(int i = 1; i< row_1 - 1;i++)
    graph_temp[i+1][1] = graph_second[i][1];

  for(int i = 2;i<c;i++)
    graph_temp[row_2][i+1] = graph_second[row_2][i];
  for(int i = row_2;i<r;i++)
    graph_temp[i+1][c] = graph_second[i][c];
  for(int i = 1;i < c;i++)
    graph_temp[r][i] = graph_second[r][i+1];
  for(int i = r; i > row_2 + 1  ; i-- )
    graph_temp[i-1][1] = graph_second[i][1];

}

int main(){

  scanf("%d %d %d",&r,&c,&t);
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      scanf("%d",&graph_temp[i][j]);
      if(graph_temp[i][j] == -1){
        graph_second[i][j] = -1;
        if(row_1 == 0){
          row_1 = i;
        }
        else{
          row_2 = i;
        }
      }
    }
  }

  for(int i = 1; i <= t; i++){
    aircon();
  }

  int result = 0;

  for(int i=1;i<=r;i++)
    for(int j=1;j<=c;j++)
      result += graph_temp[i][j];

  printf("%d",result+2);
}