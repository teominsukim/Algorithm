#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

long long line[MAX];

long long compare(const void* a, const void* b){
  return *(long long*)a - *(long long*)b ;
}

long long count_line(long long k,long long mid){
  long long count = 0;
  for(int i = 0; i < k; i++){
    count += line[i] / mid;
  }
  return count;
}

int cut_line(long long start, long long end, int k,int n){
  if(start >= end)
    return start;
  long long mid = (start + end + 1) / 2;
  int count = count_line(k,mid);
  //printf("%d",count);
  if(count >= n)
    return cut_line(mid, end, k,n);
  else 
    return cut_line(start, mid-1, k,n);
}

int main(){
  int k,n;
  scanf("%d %d",&k,&n);
  for(int i=0;i<k;i++)
    scanf("%lld",&line[i]);
  qsort(line,k,sizeof(long long),compare);
  printf("%d",cut_line(1,line[k-1],k,n));
}