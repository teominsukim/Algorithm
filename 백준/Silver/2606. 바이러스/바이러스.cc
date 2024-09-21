#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n, e;
int result = 0;
vector<int> q;
int graph[101][101];
int visited[100001];

void bfs(int start) {
  q.push_back(start);
  visited[start] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.erase(q.begin());
    for (int i = 1; i <= n; i++) {
      if (graph[cur][i] == 1 && visited[i] == 0) {
        q.push_back(i);
        visited[i] = 1;
        result++;
      }
    }
  }
}

int main() {
  cin >> n;
  cin >> e;
  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  bfs(1);
  cout << result;
}