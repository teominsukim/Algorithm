#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

//2024112777 김민수

// 숫자가 클수록 중요도가 커지는 것이다. 
// 이렇게 운영을 한 뒤에 출력이 되었을때 count 와 함꼐 출력을 한다 
// 일단 기본 동작 먼저 구현 
// 뒤에 count 구현하기 

void idot(){
    int key[10] = {0,};
    int max = 0;
    int n,m;
    cin >> n >> m;
    
    queue<pair<int,int>> doc;
    for(int i = 0; i < n; i++){
        int priority;
        cin >> priority;
        doc.push({i,priority});
        key[priority]++;
    }

    for(int i = 0; i < 10; i++){
        if (key[i] != 0) max = i;
    }

    int count = 0;

    while (!doc.empty())
    {
        pair<int,int> front = doc.front();
        doc.pop();
        //cout << front.first << front.second <<endl;

        // 아닌지 
        //cout << front.second << max << endl;
        if(front.second == max) {
            count++;
            // 찾는 값인지
            if(m == front.first) {
                cout << count << endl;
                return;
            }
            //최대 값 업데이트 
            key[front.second]--;
            if (key[front.second] == 0){
                for(int i = 0; i < 10; i++){
                    if (key[i] != 0) max = i;
                }
            } 
        } else {
            doc.push(front);
        }
    }

}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        idot();
    }
}