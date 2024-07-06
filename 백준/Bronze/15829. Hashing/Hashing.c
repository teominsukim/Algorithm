#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
  int n;
  scanf("%d",&n);
  getchar();
  char *arr = (char*)malloc(sizeof(char)*(n+1));
  long long result = 0;
  
  for(int i =0; i<n; i++)
    scanf("%c",&arr[i]);
  long long pow = 1;
  
  for(int i=0; i<n; i++){
    
    long long plus = pow*(arr[i]+1-'a') % 1234567891;
    result = (result + plus) % 1234567891;
    pow = pow * 31 % 1234567891;
  }
  
  printf("%lld",result);
  free(arr);
}