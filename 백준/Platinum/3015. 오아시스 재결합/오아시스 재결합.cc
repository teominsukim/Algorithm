#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> stack;

int main() {

  long long result = 0;
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int cnt = 1; // 같은거 세
    long long a;
    cin >> a;
    while (stack.size() > 0 && stack.back().first <= a) {
      if (stack.back().first == a)
        cnt += stack.back().second;
      result += stack.back().second;
      stack.pop_back();
    }
    if (stack.size() > 0) {
      result++;
    }
    stack.push_back({a, cnt});
  }

  cout << result;
}