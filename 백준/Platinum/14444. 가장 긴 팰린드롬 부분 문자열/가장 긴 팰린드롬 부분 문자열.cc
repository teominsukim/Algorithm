#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> p;

string changeString(const string&input){
    int len = input.length();
    vector<char> line;
    string result;
    for (int  i = 0; i < len; i++)
    {
        line.push_back('#');
        line.push_back(input[i]);   
    }
    line.push_back('#');
    result = string(line.begin(),line.end());
    return result;
}

void checkPalindromeWithManacher(const string& input){
    int len = input.length();
    p.resize(len,0);

    int center = 0, range = 0;

    for(int i = 0; i < len-1; i++){
        int mirror = 2 * center - i;

        if (i < range) {
            p[i] = min(range - i, p[mirror]);
        }

        while(i-p[i] > 0 && i-p[i] < len && input[i-p[i]-1] == input[i+p[i]+1]){
            p[i]++;
        }

        if(i + p[i] > range){
            center = i;
            range = i + p[i];
        }
    }
}



int max(const string&input){
    int len = input.length();
    int result = 0;
    int center = 0, right = 0;

    for(int i = 0; i < len; i++){
        if(p[i] > result)
            result = p[i];
    }
    
    return result;
}

int main(){
    string input;
    cin >> input;
    input = changeString(input);
    checkPalindromeWithManacher(input);
    cout << max(input);
}