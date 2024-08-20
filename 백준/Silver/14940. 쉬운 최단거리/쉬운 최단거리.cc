#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
int n = 0;
int M, N, cnt = -1;
int result[1000][1000];
int field[1000][1000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfsLogic(int r, int c) {

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nr >= M || nc < 0 || nc >= N)
      continue;
    if (field[nr][nc] == 2 || field[nr][nc] == 0)
      continue;
    field[nr][nc] = 2;
    // cout << nr << nc << ' ';
    q.push({nr, nc});
  }

  return 0;
}

int BFS() {
  n = q.size();
  // cout << n << ' ';
  for (int i = 0; i < n; i++) {
    int r = q.front().first;
    int c = q.front().second;
    result[r][c] = cnt + 1;
    // cout << r << c << ' ';
    bfsLogic(r, c);
    q.pop();
  }
  cnt++;
  return 0;
}

int main() {
  cin >> M >> N;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
      if (field[i][j] == 2) {
        q.push({i, j});
      }
    }
  }

  while (q.size() > 0) {
    BFS();
    // cout << '\n';
  }

  for(int i = 0; i < M; i++){
    for(int j = 0; j < N; j++)
      if(field[i][j] == 1)
        result[i][j] = -1;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << result[i][j] << ' ';
    }
    cout << "\n";
  }
}