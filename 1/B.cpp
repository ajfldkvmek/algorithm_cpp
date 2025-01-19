/*
    백준 10808 counting_star

    c++에서는 
    cnt['a'] 로 선언할 경우 a의 아스키 코드값인 97이 입력되어
    a[97] 과 같은 선언효과를 가진다
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;
int cnt[26];

int main(){
    cin >> str;
    for(char ch : str){
        cnt[ch - 'a']++;
    }

    for(int i = 0; i < 26; i++) cout << cnt[i] << " ";

    return 0;
}


