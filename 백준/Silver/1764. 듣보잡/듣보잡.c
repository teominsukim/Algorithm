#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) { return (a < b) ? a : b; }

int compare(const void *a, const void *b){
  const char *str1 = (const char **)a;
  const char *str2 = (const char **)b;
  return strcmp(str1,str2);
}

int main(){

  int count = 0;
  int n,m;
  scanf("%d %d",&n,&m);
  getchar();
  char N[n][20];
  char M[m][20];
  int mmin = min(n,m);
  char result[mmin][20];

  for(int i = 0; i < n; i++){
    scanf("%s",N[i]);
  }
  for(int i = 0; i < m; i++){
    scanf("%s",M[i]);
  }

  qsort(N,n,sizeof(N[0]),compare);
  qsort(M,m,sizeof(M[0]),compare);

  int i = 0, j = 0;
  while(1){
    int cmp = strcmp(N[i],M[j]);
    if(cmp == 0){
      strcpy(result[count++],N[i]);
      i++;
      j++;
    }
    else if(cmp < 0){
      i++;
    }
    else{
      j++;
    }
    if(i == n || j == m) 
      break;
  }

  printf("%d\n",count);
  for(int k = 0; k < count; k++){
    printf("%s\n",result[k]);
  }
  
}