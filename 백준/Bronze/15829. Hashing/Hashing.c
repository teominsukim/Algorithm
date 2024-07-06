#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
  int n;
  scanf("%d",&n);
  getchar();
  char *arr = (char*)malloc(sizeof(int)*n);
  long long result = 0;
  
  for(int i =0; i<n; i++)
    scanf("%c",&arr[i]);
  
  for(int i=0; i<n; i++){
    int plus = (pow(31,i)*(arr[i]+1-'a'));
    result += plus % 1234567892;
  }
  
  printf("%lld",result);
}