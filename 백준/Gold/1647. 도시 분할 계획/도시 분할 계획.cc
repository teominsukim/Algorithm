#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 꼭 다 연결 될 필요는 없는 것이구만
// 그러한 최소 스패닝 트리 - 걍 최소 스패닝 트린데 조건이 다른거 아냐?
int parent[100001];
vector<pair<int, pair<int, int>>> edge;

int find_parent(int x) {
  if (parent[x] == x)
    return x;
  else
    return find_parent(parent[x]);
}

int main() {
  int result = 0;
  int cnt = 0;
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, {a, b}});
  }
  sort(edge.begin(), edge.end());
  for (int i = 1; i <= N; i++)
    parent[i] = i;
  int i = 0;
  while (cnt != N - 2) {
    int A = edge[i].second.first;
    int B = edge[i].second.second;
    int Ar = min(find_parent(A), find_parent(B));
    int Br = max(find_parent(A), find_parent(B));
    int C = edge[i].first;
    if (Ar != Br) {
      parent[Br] = Ar;
      result += C;
      cnt++;
    }
    i++;
  }
  cout << result;
}