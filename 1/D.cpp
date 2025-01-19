/*
    회문인지 체크하기
*/
#include<bits/stdc++.h>
using namespace std;

string str, temp;

int solve() {
   int ret = 0;
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());

    // cout << str << endl;
    // cout << temp << endl;

    if(temp == str) ret = 1; 

    return ret;
}

int main(){

    int ret = solve();  

    cout << ret << endl;

    return 0;
}