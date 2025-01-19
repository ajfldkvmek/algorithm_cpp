/*
    첫째 줄에 선수의 수 N (1 ≤ N ≤ 150)이 주어진다. 다음 N개 줄에는 각 선수의 성
    성의 첫 글자가 같은 선수가 5명보다 적다면, 상근이는 내일 있을 친선 경기를 기권

    다섯 명을 선발할 수 없는 경우에는 "PREDAJA" (따옴표 없이)를 출력

    선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력한다.

*/

#include<bits/stdc++.h>
using namespace std;

int num;
string name, ret;
int arr[26];

int main(){

    int cnt = 0;
    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> name;
        arr[name[0] - 'a']++;
    }
    // for(int i = 0; i < 26; i++){
    //     if(arr[i] >= 5) cout << char(i + 'a');
    //     else cnt++;
    // }
    for(int i = 0; i < 26; i++){
        if(arr[i] >= 5) ret += i+'a';
    }

    if(ret.size()) cout << ret << endl;
    else cout << "PREDAJA" << endl;

    return 0;
}