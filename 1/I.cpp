#include<bits/stdc++.h>
using namespace std;
/*
    언제 std::endl을 사용해야 할까?
    디버깅: 즉시 출력 결과를 확인해야 할 때.
    실시간 응답이 필요한 경우(예: 네트워크 로그, 사용자 입력 대기).

    언제 "\n"을 사용해야 할까?
    일반적인 출력 작업.
    성능이 중요한 경우, 특히 반복적으로 출력해야 할 때.

    성능: "\n"이 더 빠르다. 
    단순 출력작업을 위해서는 개행문자를 사용하는 것이 더 효과적

    의도: 실시간 플러시가 필요하면 std::endl, 그렇지 않으면 "\n"을 사용하는 것이 적합합니다.
    일반적으로는 "\n"을 선호하는 것이 좋습니다.
*/
string s;
map<string ,int> mp1;
map<int, string> mp2;
int n, m;
string a[100004];

int main()  {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> s;
        mp1[s] = i;
        mp2[i] = s;
        a[i] = s;
    }

    for(int i = 1; i <= m; i++){
        cin >> s;
        // atoi :: ascii to int 로 char 을 int 로 바꿔주는 기능을 함
        if(atoi(s.c_str()) == 0) {
            cout << mp1[s] << "\n";
        } else {
            cout << mp2[atoi(s.c_str())] << "\n";
        }
    }

    return 0;

}