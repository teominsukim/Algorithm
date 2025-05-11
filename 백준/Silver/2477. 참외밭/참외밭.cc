#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// 입력순서가 달라도 되는거였음? 
// 아니 순서대로 주어져야 하는건데?

int main() {
    // 일단 빙글빙글 도는게 가능하려면 
    // 동 1 -> 북 4 -> 서 2 -> 남 3
    // 틀에서 벗어나는 수상한 행동을 하는 친구를 찾아내자 

    int way[4][2] = {{1,4},{4,2},{2,3},{3,1}};
    int m;
    vector<pair<int,int>> input (6);

    cin >> m;
    for(int i = 0; i < 6; i++){
        cin >> input[i].first >> input[i].second;
    }

    int find;
    int result = 1;

    for(int i = 0; i < 6; i++){
        int judge = 0;
        int ppp;
        if(i != 5){
            ppp = i+1;
        } else {
            ppp = 0;
        }
        for(int j = 0; j < 4; j++){
            if(way[j][0] == input[i].first && way[j][1] == input[ppp].first){
                judge = 1;
                //cout << 1 << endl;
                //cout << i <<" "<< i+1 << endl;
            }
        }
        if(judge == 0){
                find = input[i].second * input[ppp].second;
                break;
        }
    }

        for(int j = 1; j <= 4; j++){
            int count = 0;
            int index;
            for(int i = 0; i < 6; i++){
                if(input[i].first == j){
                count++;
                index = i;
                } 
            }
            if(count == 1) result *= input[index].second;
        }

    //cout<< result;

    cout << m*(result - find);

}