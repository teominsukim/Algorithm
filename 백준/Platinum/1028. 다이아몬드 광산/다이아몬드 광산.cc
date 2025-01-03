#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string buff[750];

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int R, C;
  int diag[750][750][2] = {{{0}}};
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> buff[i];
  }
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {

      if (diag[r][c][0] == 0) {
        int dr = r, dc = c;
        int level = 0;
        while (dr < R && dc >= 0) {
          if (buff[dr][dc] == '0')
            break;
          level++;
          dr++;
          dc--;
        }
        for (int i = 0; i < level; i++) {
          diag[r + i][c - i][0] = level - i;
        }
      }

      if (diag[r][c][1] == 0) {
        int dr = r, dc = c;
        int level = 0;
        while (dr < R && dc < C) {
          if (buff[dr][dc] == '0')
            break;
          level++;
          dr++;
          dc++;
        }

        for (int i = 0; i < level; i++) {
          diag[r + i][c + i][1] = level - i;
        }
      }
    }
  }

  int max = 0;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {

      int k = min(diag[i][j][0], diag[i][j][1]);

      while (k >= 1) {
        if (diag[i + (k - 1)][j - (k - 1)][1] >= k && diag[i + (k - 1)][j + (k - 1)][0] >= k) {
          max = max > k ? max : k;
        }
        k--;
      }
    }
  }

  // for (int i = 0; i < R; i++) {
  //   for (int j = 0; j < C; j++) {
  //     cout << diag[i][j][0] << " ";
  //   }
  //   cout << "\n";
  // }

  // cout << "\n";

  // for (int i = 0; i < R; i++) {
  //   for (int j = 0; j < C; j++) {
  //     cout << diag[i][j][1] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << max;
}