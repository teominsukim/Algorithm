#include <stdio.h>
#include <stdlib.h>

int n;
int tri[500][500];

int main(){
  scanf("%d",&n);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++)
      scanf("%d",&tri[i][j]);
  }

  for(int i=n-1; i > 0; i--){
    for(int j=0; j < i; j++){
      tri[i-1][j] += tri[i][j] > tri[i][j+1] ? tri[i][j] : tri[i][j+1];
    }
  }

  printf("%d",tri[0][0]);
  
}