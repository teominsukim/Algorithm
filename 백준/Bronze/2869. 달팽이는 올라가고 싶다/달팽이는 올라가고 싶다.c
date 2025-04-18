#include <stdio.h>

int main(){
  int a,b,v;
  int count = 1;
  scanf("%d %d %d",&a,&b,&v);

  v -= a;
  count += v / (a-b);
  if(v % (a-b) != 0)
    count++;

  printf("%d",count);
  
}