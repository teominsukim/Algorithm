#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

// 일단 데이터 셋
vector<long long> arr;
vector<long long> tree;

// 함수들
long long fermat(long long arr){
  //return arr ** (mod - 2) % mod;
  long long modint = mod-2;
  long long result = 1;

  while(modint > 0){
    if (modint % 2 == 1) { 
      result = (result * arr) % mod;
    }
    arr = (arr * arr) % mod; 
    modint /= 2;
  }

  return result % mod;
}

long long init(vector<long long> &tree, int node, int start, int end) {
  if (start == end)
    return tree[node] = arr[start];
  int mid = (start + end) / 2;
  return tree[node] = ((init(tree, node * 2, start, mid) % mod) *
                      (init(tree, node * 2 + 1, mid + 1, end) % mod)) % mod;
}

long long pro(int node, int start, int end, int left, int right) {
  if (left > end || right < start)
    return 1;
  if (left <= start  && end <= right)
    return tree[node];
  int mid = (start + end) / 2;
  return ((pro(node * 2, start, mid, left, right) % mod) *
         (pro(node * 2 + 1, mid + 1, end, left, right) % mod )) % mod;
}

void update(int node, int start, int end, int index, long long arr, long long c) { 

  if (index < start || index > end)
    return;
  
  tree[node] = (tree[node] * fermat(arr)) % mod; 
  tree[node] = (tree[node] * (c % mod)) % mod;
  
  if (start != end) {
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, arr, c);
    update(node * 2 + 1, mid + 1, end, index, arr, c);
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
      if(arr[b] == 0) {
        arr[b] = c;
        init(tree, 1, 1, n );
      }
      update(1, 1, n , b , arr[b] , c);
      arr[b] = c;
    }
    else if (a == 2)
      cout << pro(1, 1, n , b , c ) << endl;
    // if( i == 2){
    //   for(int j = 1; j <= 9; j++)
    //     cout << tree[j] << " ";
    // }
  }
}