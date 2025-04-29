#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 먼저 의견의 개수 받고 
// 정렬
// 절사 해야 할 인원 계산 
// 인덱스로 계산하기 -> 더해서 평균 내는 

// 2명 총 4명을 제외 해야 한다. 
// 2번째 사람부터 7번째

int main(){
    double n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    vector<int> opinion(n);
    for(int i = 0; i < n; i++){
        cin >> opinion[i];
    }
    // 정렬
    sort(opinion.begin(),opinion.end());
    // 절사해야 할 
    float start = n*3/20;
    start = round(start);
    // 인덱스로 계산하기 
    int m = 0;
    for(int i = start; i < n - start; i++){
        m += opinion[i];
        //cout << opinion[i] << endl;
    }
    n -= 2*start;
    double result = m / n;
    result = round(result);
    int fuck = result;
    cout << fuck << endl;
}