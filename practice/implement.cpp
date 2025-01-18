#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, temp, b;
string str = "abced";

int main(){

    //1. c++ 의 문자열 함수
    //substr::문자열 구간 복사
    string str2 = str.substr(0,3);
    cout << str2 << endl;

    //reverse::문자열 뒤집기
    reverse(str2.begin(), str2.end());
    cout << str2 << endl;

    //문자열 추가
    str2 += "zxc";
    cout << str2 << endl;


    //2.정렬, 평균값
    cin >> n;
    for(int i =0; i < n; i++){
        cin >> temp;
        b += temp;
        v.push_back(temp);
    }
    //기본적으로 c++ 에서의 정렬함수는 오름차순임
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
    cout << endl;

    //소수점 자리 설정
    cout << fixed << setprecision(2) << (b / n) << endl;

    return 0;
}