#include <stdio.h>
#include <stdlib.h>

int main(){
  int number[1000];
  int dp_max[1000];
  int dp_min[1000];
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&number[i]);
  for(int i = 0; i< n; i++)
    dp_max[i] = 1;

  for(int i = 1; i < n; i++){
    int max = 1;
    for(int j = 0; j < i; j++){
      if(number[j] < number[i])
        max = max > dp_max[j] + 1 ? max : dp_max[j] + 1;
    }
    dp_max[i] = max;
  }

  for(int i = n-1; i>=0; i--){
    int min = 1;
    for(int j = n-1; j > i; j--){
      if(number[j] < number[i])
        min = min > dp_min[j] + 1 ? min : dp_min[j] + 1;
    }
    dp_min[i] = min;
  }

  int r_max = 0;
  for(int i = 0; i < n; i++){
    if(r_max < dp_max[i] + dp_min[i] - 1)
      r_max = dp_max[i] + dp_min[i] - 1;
  }

  printf("%d",r_max);
}