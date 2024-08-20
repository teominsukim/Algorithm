#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100000
// 응? 이거 세그먼트 트리로 풀수 있지 않나

int arr[MAX];
long long tree[MAX * 4];

long long init(int node, int start, int end) {
  if (start == end) {
    tree[node] = arr[start];
    return tree[node];
  }
  int mid = (start + end) / 2;

  tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
  return tree[node];
}

long long result(int node, int start, int end, int a, int b) {
  if (a > end || b < start)
    return 0;
  if (a <= start && end <= b)
    return tree[node];
  int mid = (start + end) / 2;
  return result(node * 2, start, mid, a, b) +
         result(node * 2 + 1, mid + 1, end, a, b);
}

int main() {
  int N, M;
  cin >> N >> M;

  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ios::sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  init(1, 1, N);

  // for(int i = 1; i < 10; i++)
  //   cout << tree[i];

  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    printf("%lld\n", result(1, 1, N, a, b));
  }
}