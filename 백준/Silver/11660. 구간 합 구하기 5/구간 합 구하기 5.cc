#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

int graph[1024][1024];
int sum[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    memset(sum, 0, sizeof(sum));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] = graph[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
        }
    }

    int x1, x2, y1, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = sum[x2][y2] - (sum[x1 - 1][y2] + sum[x2][y1 - 1] - sum[x1 - 1][y1 - 1]);
        cout << result;
        cout << "\n";
    }
}
