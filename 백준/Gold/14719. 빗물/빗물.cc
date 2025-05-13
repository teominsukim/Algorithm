#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<int> rain(w);

    for(int i = 0; i < w; i++){
        cin >> rain[i];
    }

    // 아 맨 끝만 보면 안되는구나 
    // 하나하나 확장을 해나가면서 해결을 해야겠군 
    // 500 이니까 브루트 포싱 

    int block = rain[0];

    int result = 0;

    for(int i = 1; i < w-1; i++){
        int max_h = 0;
        for(int j = i + 1; j < w; j++){
            if(max_h < rain[j] && rain[i] < rain[j]) max_h = rain[j];
        }

        if(max_h == 0){
            //cout << "LIFE" << endl;
            if(rain[i] > block) block = rain[i];
            continue;
        } 

        if(max_h >= block && block > rain[i]) {
            result += (block - rain[i]);
        }
        else if (max_h < block && block > rain[i]){
            result += (max_h - rain[i]);
        }

        if(rain[i] > block) block = rain[i];
        
        // cout << block << endl;
        // cout << rain[i] << endl;
        // cout << max_h << endl;
        // cout << result << endl;
    }

    cout << result << endl;
}