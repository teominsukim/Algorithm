#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int n, m;
char tool[13][13];
int map[13][13];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct info
{
  int ry, rx, by, bx, count;
};

info start;

void printall()
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
void bfs()
{
  int visited[12][12][12][12] = {
      0,
  };
  start.count = 0;
  queue<info> q;
  q.push(start);

  visited[start.ry][start.rx][start.by][start.bx] = 1;

  while (!q.empty())
  {
    info cur = q.front();
    q.pop();
    if (cur.count > 10){
      cout << -1;
      return;
      break;
    }
    if (map[cur.ry][cur.rx] == -1 && map[cur.by][cur.bx] != -1)
    {
      cout << cur.count;
      return;
    }
    for (int i = 0; i < 4; i++)
    {
      info next;
      next.bx = cur.bx;
      next.by = cur.by;
      next.rx = cur.rx;
      next.ry = cur.ry;
      while (1)
      {
        next.rx += dx[i];
        next.ry += dy[i];
        if (map[next.ry][next.rx] == 1)
        {
          next.rx -= dx[i];
          next.ry -= dy[i];
          break;
        }
        if (map[next.ry][next.rx] == -1)
        {
          break;
        }
      }
      while (1)
      {
        next.bx += dx[i];
        next.by += dy[i];
        if (map[next.by][next.bx] == 1)
        {
          next.bx -= dx[i];
          next.by -= dy[i];
          break;
        }
        if (map[next.by][next.bx] == -1)
        {
          break;
        }
      }
      // red blue 가 겹치는 경우에 대한 예외처리
      if (next.rx == next.bx && next.by == next.ry)
      {
        if (map[next.ry][next.rx] != -1)
        {
          int b_dis = abs(next.by - cur.by) + abs(next.bx - cur.bx);
          int r_dis = abs(next.ry - cur.ry) + abs(next.rx - cur.rx);
          if (r_dis < b_dis)
          {
            next.bx -= dx[i];
            next.by -= dy[i];
          }
          else
          {
            next.rx -= dx[i];
            next.ry -= dy[i];
          }
        }
      }
      if (visited[next.ry][next.rx][next.by][next.bx] == 0 && map[next.by][next.bx] != -1)
      {
        next.count = cur.count + 1;
        //cout << next.ry << next.rx << next.by << next.bx << endl;
        q.push(next);
        visited[next.ry][next.rx][next.by][next.bx] = 1;
      }
    }
  }
  cout << -1;
  return;
}

void input()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> tool[i][j];
      if (tool[i][j] == '#')
        map[i][j] = 1;
      else if (tool[i][j] == '.')
        map[i][j] = 0;
        else if (tool[i][j] == 'R') {
          map[i][j] = 0; 
          start.ry = i;
          start.rx = j;
        }
        else if (tool[i][j] == 'B') {
          map[i][j] = 0;
          start.by = i;
          start.bx = j;
        }
      else if (tool[i][j] == 'O')
        map[i][j] = -1;
    }
  }
}

int main()
{
  input();
  bfs();
}