#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

// 두 칸의 거리 == 지나야 하는 칸의 수 
// 이동은 8 방향이 가능하다

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

int n,m;
int map[51][51];

int bfs(int i, int j) {

    queue<pair<int,int>> q;
    int visit[51][51] = {0};

    q.push({i,j});
    int curr_i, curr_j;

    while(!q.empty()) {
        // 팝하고 
        curr_i = q.front().first;
        curr_j = q.front().second;
        q.pop();

        // 밑에 순회하며 추가하기 
        for(int i = 0; i < 8; i++){
            int new_i = dx[i] + curr_i;
            int new_j = dy[i] + curr_j;
            if(map[new_i][new_j] == 1) return visit[curr_i][curr_j] + 1;
            if(visit[new_i][new_j] == 0 && new_i >= 0 && new_i < n && new_j >= 0 && new_j < m){
                q.push({new_i,new_j});
                visit[new_i][new_j] = visit[curr_i][curr_j] + 1;
            }
        }
    }
    
    return 0;
    
}

// bfs 알고리즘 1.첫번째 push 2.큐에서 팝 3. 밑에 단계 순회하며 큐에 삽입 
//

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == 0) {
                int p = bfs(i,j);
                if(max < p) max = p;
            }
        }
    }

    cout << max;

}