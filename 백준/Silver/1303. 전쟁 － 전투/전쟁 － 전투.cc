#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 문자 배열 
// dfs 통해서 탐색하기 
// 결과 값 저장하는 동작 

int n,m;
vector<string> war;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int visited[101][101];

int count_s;

void dfs(char color, int row, int con){
    if(visited[row][con] == 1)
        return;
    count_s++;
    visited[row][con] = 1;
    for(int i = 0; i < 4; i++){
        int new_x = row + dx[i];
        int new_y = con + dy[i];
        if(new_x < m && new_x >= 0 && new_y < n && new_y >= 0){
            if(color == war[new_x][new_y] && visited[new_x][new_y] == 0){
                //count_s++;
                //visited[new_x][new_y] = 1;
                dfs(color,new_x,new_y);
            } 
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    int result_w = 0;
    int result_b = 0;
    war.resize(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> war[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            count_s = 0;
            dfs(war[i][j],i,j);
            //cout << count_s << endl;
            if(war[i][j] == 'W')result_w += count_s * count_s;
            else result_b += count_s * count_s;
        }
    }
    cout << result_w <<" "<< result_b;
}