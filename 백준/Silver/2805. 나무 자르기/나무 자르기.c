#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000
int n,m;
int arr[MAX];

long long calculate(int h){
  long long result = 0;
  for(int i = 0; i < n; i++){
    if(arr[i]-h > 0)
    result += arr[i]-h;
  }
  return result;
}

int cut(int start,int end){
  long long close = MAX;
  long long result;
  while(start <= end){
    int mid = (start+end)/2;
    //printf("%d",mid);
    long long c = calculate(mid);
    //printf(" %d\n",c);
    long long temp = c - m;
    if(temp == 0){
      return mid;
    }
    else if(temp > 0){
      start = mid+1;
      if(close > labs(temp)){
        close = temp;
        result = mid;
      }
    }
    else{
      end = mid-1;
    }
  }

  return result;
  
}

int main(){
  int max = 0;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    if(arr[i] > max) max = arr[i];
  }

  printf("%d",cut(0,max));
  
}