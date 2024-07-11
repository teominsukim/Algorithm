#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line1[1000];
char line2[1000];
int LCS[1002][1002];

int max(int a, int b) {
    return (a > b) ? a : b;
}

// LCS[i][j]의 값은0번째 글자에서 i번쨰 글자, j번째 글자까지의 최장 부분수열의 길이를 의미한다

int main(){
  scanf("%s",line1);
  scanf("%s",line2);
  int len1 = strlen(line1);
  int len2 = strlen(line2);

  for(int i = 0; i <= len1; i++){
    for(int j = 0; j <= len2; j++){
      if( i == 0 || j == 0){
        LCS[i][j] = 0;
        continue;
      }
      else if(line1[i-1] == line2[j-1])
        LCS[i][j] = LCS[i-1][j-1] + 1;
      else 
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
    }
  }

  

  printf("%d",LCS[len1][len2]);
}