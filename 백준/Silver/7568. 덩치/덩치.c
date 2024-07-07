#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int weight;
  int height;
  int index;
}people;

int compare(people *a, people *b){
  int i = a->weight;
  int j = b->weight;
  return j - i;
}

int main(){
  int n;
  int k = 1;
  scanf("%d",&n);
  people *p = (people*)malloc(sizeof(people)*n);
  // 입력받고
  for(int i = 0; i < n; i++)
    {
      scanf("%d %d",&p[i].weight,&p[i].height);
      p[i].index = i;
    }
  int result[n];
  qsort(p,n,sizeof(people),compare);

  for(int i = 0; i < n; i++){
    k = 1;
    for(int j = 0; j < i; j++)
      if( p[j].height > p[i].height && p[j].weight != p[i].weight )
        k++;

    result[p[i].index] = k;
  }

  for(int i = 0; i <n; i++)
    printf("%d ",result[i]);

  printf("\n");

  return 0;
}