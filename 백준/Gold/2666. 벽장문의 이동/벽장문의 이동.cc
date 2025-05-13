#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int result = 0;

int n;
int a,b;
int m;
vector<int> list(m);

int find(int a, int b, int i,int result) {

    if(i == m) return result;

    if(list[i] <= a) {
            result += abs(list[i]-a);
            return find(list[i],b,i+1,result);
    } else if(b <= list[i]) {
            result += abs(list[i]-b);
            return find(a,list[i],i+1,result);
    } else {
        int r1 = find(list[i],b,i+1,result + abs(list[i] - a));
        int r2 = find(a,list[i],i+1,result + abs(list[i] - b));
        return min(r1,r2);
    }

    return result;
}

int main(){
    cin >> n;
    cin >> a >> b;
    cin >> m;
    list.resize(m);
    for(int i = 0; i < m; i++){
        cin >> list[i];
    }

    cout << find(a,b,0,0);
}