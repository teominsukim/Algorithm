#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

int main() {
    long long n; 
    cin >> n;
    n--;
    int len = 1;

    while (n >= pow(2,len)){
        n -= pow(2,len);
        len++;
    }

    //cout << len;

    bitset<32> b(n);
    for(int i = len - 1; i >= 0; i--) {
        if(b[i] == 1){
            cout << "7";
        } else cout << "4";
    }

}