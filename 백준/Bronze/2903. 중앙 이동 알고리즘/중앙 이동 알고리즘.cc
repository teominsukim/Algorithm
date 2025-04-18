#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

int result = 4;
int i = 0;
int j = 2;

void reculsive (int n){
    if(n == 1){
        cout << result;
        return;
    } 
    result += (pow(4,i) + j*2*pow(2,i));
    j = j + j - 1;
    i++;
    reculsive(n-1);
}

int main(){
    int n;
    cin >> n;
    reculsive(n+1);
}