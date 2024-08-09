#include <iostream>
#include <vector>
using namespace std;

// 일단 데이터 셋
vector<long long> arr;
vector<long long> tree;

// 함수들
long long init(vector<long long> &tree, int node, int start, int end) {
  if (start == end)
    return tree[node] = arr[start];
  int mid = (start + end) / 2;
  return tree[node] = init(tree, node * 2, start, mid) +
                      init(tree, node * 2 + 1, mid + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start)
    return 0;
  if (left <= start  && end <= right)
    return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) +
         sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index, long long diff) { 

  if (index < start || index > end)
    return;
  //cout << diff;
  tree[node] += diff;
  //cout << tree[node];
  if (start != end) {
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
  }
 
}

// 그리고 메인함수
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  arr.resize(n+1);
  tree.resize(4 * n +1);

  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  init(tree, 1, 1, n );

  for (int i = 0; i < m + k; i++) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    if (a == 1) {
      long long diff = c - arr[b];
      arr[b] = c;
      update(1, 1, n , b , diff);
    }
    else if (a == 2)
      cout << sum(1, 1, n , b , c ) << endl;
  }
}
