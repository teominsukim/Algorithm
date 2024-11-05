#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    long long k;
    long long r;
    long long result = 0;
    long long m = 0;
    long long arr[1000000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        m += arr[i];
    }
    k = m / n;
    r = m % n;
    for(int i = 0; i < n; i++) {
        if(arr[i] > k && r > 0){
            result += arr[i] - (k+1);
            r--;
        } else if(arr[i] > k) {
            result += arr[i] - k;
        }
    }
    cout << result;
}