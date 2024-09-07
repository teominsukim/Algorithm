#include <math.h>
#include <stdio.h>
#include <string.h>

int N;
int arr[100001];
int r_l, r_r;

int divide() {
  int left = 1;
  int right = N;
  int min = 2000000000;
  int sum;

  while (left != right) {
    sum = arr[left] + arr[right];
    if (min > abs(sum)) {
      r_l = arr[left];
      r_r = arr[right];
      min = abs(sum);
    }
    if (sum == 0) {
      return 0;
    } else if (sum > 0) {
      right--;
    } else {
      left++;
    }
  }
  return 0;
}

int main() {

  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", &arr[i]);
  divide();
  printf("%d %d", r_l, r_r);
}