#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<float, pair<int, int>>> edge;
vector<pair<float, float>> node;
int parent[101];
float result = 0;
int r_l, r_r;
int n;

int find_node(int i) {
  float weight;
  for (int j = i + 1; j <= n; j++) {
    weight = pow(node[i - 1].first - node[j - 1].first, 2) +
             pow(node[i - 1].second - node[j - 1].second, 2);
    weight = sqrt(weight);
    edge.push_back({weight, {i, j}});
  }
  return 0;
}

int find_root(int a) {
  if (parent[a] == a)
    return a;
  return parent[a] = find_root(parent[a]);
}

float mst() {
  for (int i = 1; i <= n; i++)
    parent[i] = i;
  int count = 0;
  int i = 0;
  while (count != n - 1) {

    int a = min(edge[i].second.first, edge[i].second.second);
    int b = max(edge[i].second.first, edge[i].second.second);

    if (find_root(a) != find_root(b)) {
      parent[find_root(a)] = find_root(b);
      result += edge[i].first;
      count++;
    }
    
    i++;
  }

  return result;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    float x, y;
    cin >> x >> y;
    node.push_back({x, y});
  }
  for (int i = 1; i <= n; i++) {
    find_node(i);
  }
  sort(edge.begin(), edge.end());
  cout << mst();
}