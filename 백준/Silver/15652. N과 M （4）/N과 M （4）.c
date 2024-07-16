#include <stdio.h>
int m,n;
int arr[8];

int function(int a,int b){

  arr[b-1] = a;
  if(b == n){
    for(int i = 0;i < n;i++)
      printf("%d ",arr[i]);
    printf("\n");
    return 0;
  }
  
  for(int i = a; i <= m; i++)
    function(i,b+1);

  return 0;
}

int main(){
  scanf("%d %d",&m,&n);
  for(int i = 1; i <= m; i++)
    function(i,1);
}