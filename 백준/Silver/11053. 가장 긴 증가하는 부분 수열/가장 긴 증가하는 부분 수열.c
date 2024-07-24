#include <stdio.h>
#include <stdlib.h>

int main(){
  int number[1000];
  int dp[1000];
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&number[i]);
  for(int i = 0; i< n; i++)
    dp[i] = 1;

  for(int i = 1; i < n; i++){
    int max = 1;
    for(int j = 0; j < i; j++){
      if(number[j] < number[i])
        max = max > dp[j] + 1 ? max : dp[j] + 1;
    }
    dp[i] = max;
  }

  int r_max = 0;
  for(int i = 0; i < n; i++)
    if(dp[i] > r_max)
      r_max = dp[i];


  printf("%d",r_max);
}