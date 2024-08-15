#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<pair<int, int>> q;
int n = 0;
int M, N, cnt = -1;
int field[1000][1000];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int bfsLogic(int r, int c) {

  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr < 0 || nr >= M || nc < 0 || nc >= N)
      continue;
    if (field[nr][nc] == 1 || field[nr][nc] == -1)
      continue;
    field[nr][nc] = 1;
    //cout << nr << nc << ' ';
    q.push({nr, nc});
  }

  return 0;
}

int BFS() {
  n = q.size();
  //cout << n << ' ';
  for (int i = 0; i < n; i++) {
    int r = q.front().first;
    int c = q.front().second;
    //cout << r << c << ' ';
    bfsLogic(r, c);
    q.pop();
  }
  cnt++;
  return 0;
}

int check() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++)
      if (field[i][j] == 0)
        return 1;
  }
  return 0;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> field[i][j];
      if (field[i][j] == 1) {
        q.push({i, j});
      }
    }
  }
  
  while (q.size() > 0) {
    BFS();
    //cout << '\n';
  }


  if (check() == 1) {
    cout << -1;
    return 0;
  }

  cout << cnt;
}