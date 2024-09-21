#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int w, h;

int graph[50][50];

int bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  graph[a][b] = 0;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w)
        continue;
      if (graph[nx][ny] == 1) {
        graph[nx][ny] = 0;
        q.push({nx, ny});
      }
    }
  }
  return 0;
}

int find(int w, int h) {
  int result = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (graph[i][j] == 1) {
        bfs(i, j);
        result++;
      }
  memset(graph, 0, sizeof(graph));
  return result;
}

int main() {
  while (true) {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> graph[i][j];
      }
    }
    if (w == 0 && h == 0)
      break;
    cout << find(w, h) << "\n";
    // for (int i = 0; i < h; i++) {
    //   for (int j = 0; j < w; j++) {
    //     cout << graph[i][j];
    //   }
    //   cout << "\n";
    // }
    memset(graph, 0, sizeof(graph));
  }
}