#include <stdio.h>
#include <stdlib.h>

int paper[128][128];
int blue = 0;
int white = 0;

int four(int n, int row, int col){

  // 현재 색종이 문제 분할 필요성 검증
  int count = 0;
  int first_color = paper[row][col];
  for(int i = row; i < row + n; i++)
    for(int j = col; j < col + n; j++){
      if(paper[i][j] != first_color)
        break;
      else
        count++;
    }
  if(count == n*n){
    if(paper[row][col] == 0)
      white++;
    else
      blue++;
    return 0;
  }

  // 분할
  int n2 = n / 2;

  if(n2 == 1){
    for(int i = row; i < row + n; i++)
      for(int j = col; j < col + n; j++){
        if(paper[i][j] == 0)
          white++;
        else
          blue++;
      }
    return 0;
  }
  
  four(n2, row, col);
  four(n2, row+n2, col);
  four(n2, row, col+n2);
  four(n2, row+n2, col+n2);

  return 0;
    
}

int main(){
  int n; 
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanf("%d",&paper[i][j]);
  four(n, 0, 0);
  printf("%d\n%d",white,blue);
}