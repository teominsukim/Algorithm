#include <stdio.h>
#include <stdlib.h>
#define MAX 101

int LCS[MAX][MAX];
int LCS_C[MAX][MAX];
int a,b;
int count = 0;
int result[101];
int A[MAX], B[MAX];

int check(int k){
  
  for(int i = 0; i < a; i++){
    if(A[i] == k){
      for(int j = 0; j < b; j++)
        if(LCS_C[i+1][j+1] == 1){
          find_max(i,j);
          return 1;
        }
    } 
  }

  return 0;
  
}

int find_max(int w,int e){

  int max = 0;
  int x,y;
  
  for(int i = w; i < a; i++){
    for(int j = e; j < b; j++)
      if(LCS_C[i+1][j+1] == 1){
        if(max < A[i]){
          max = A[i];
          x = i;
          y = j;
        }
      }
  }

  if(max == 0)
    return 0;
  
  else{
    result[count++] = max;
    find_max(x+1,y+1);
  }
  
}

int main(){
  scanf("%d",&a);
  for(int i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(int i = 0; i < b; i++){
    scanf("%d",&B[i]);
  }

  // LCS 알고리즘을 구현 한 것이고 
  for(int i = 0; i <= a; i++){
    for(int j = 0; j <= b; j++){
      LCS_C[i][j] = 0;
      if(i == 0 || j == 0)
        LCS[i][j] = 0;
      else if(A[i-1] == B[j-1]){
        LCS[i][j] = LCS[i-1][j-1] + 1;
        LCS_C[i][j] = 1;
      }
      else
        LCS[i][j] = (LCS[i-1][j] > LCS[i][j-1]) ? LCS[i-1][j] : LCS[i][j-1];
    }
  }

  // a를 기준으로 하여서....

  for(int k = 100; k >=1; k--){
    int n = check(k);
    if(n == 1)
      break;
  }

  printf("%d\n",count);
  for(int i = 0; i < count; i++)
    printf("%d ",result[i]);
  
}