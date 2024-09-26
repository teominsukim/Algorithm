#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector <int> q;
vector<int> connect;  
vector<bool> visited; 

void bfs(int n){
  int current;
  q.push_back(n);
  visited[n] = 1;
  
  while(!q.empty()){         
    current = q.front();
    q.erase(q.begin());
    cout << current << " ";
    visited[current] = 1;

    for(int next : graph[current]){
      connect[next]--;
      if(connect[next] == 0 && !visited[next]) {
        visited[next] = 1;
        q.push_back(next);
      }
    }
     
    // for(int i = 1; i <= N; i++){
    //   if(graph[current][i] == 1 && visited[i] == 0)
    //     connect[i]--;
    // }
    
    // for(int i = 1; i <= N; i++){
    //   if(graph[current][i] == 1 && visited[i] == 0 && connect[i] == 0)
    //     q.push_back(i);
    // }
    
  }
}

int main() {
  cin >> N >> M;
  graph.resize(N+1);
  connect.resize(N + 1);
  visited.resize(N + 1);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    connect[b]++;
  }
  for(int i = 1; i <= N; i++)
    if(connect[i] == 0 && !visited[i])
      bfs(i);
  for(int i = 1; i <= N; i++)
    if(visited[i] == 0)
      cout << i << " ";
  return 0;
}