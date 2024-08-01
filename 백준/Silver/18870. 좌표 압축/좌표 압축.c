#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int xo;
  int xp_1;
  int xp_2;
}cord;

int compare(const void *a, const void *b){
  cord A = *(cord *)a;
  cord B = *(cord *)b;
  return A.xo - B.xo;
}

int compare_2(const void *a, const void *b){
  cord A = *(cord *)a;
  cord B = *(cord *)b;
  return A.xp_1 - B.xp_1;
}

int main(){
  int n;
  scanf("%d",&n);
  cord* line = (cord*)malloc(sizeof(cord)*n);
  for(int i=0;i<n;i++){
    scanf("%d",&line[i].xo);
    line[i].xp_1 = i;
  }
  
  qsort(line,n,sizeof(cord),compare);

  int j = 0;
  line[0].xp_2 = 0;
  for(int i=1;i<n;i++){
    if(line[i].xo != line[i-1].xo)
      j++;
    line[i].xp_2 = j;
  }

  qsort(line,n,sizeof(cord),compare_2);

  for(int i =0; i < n; i++)
    printf("%d ",line[i].xp_2);
  
}