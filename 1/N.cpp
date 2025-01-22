/*
 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램
 A, B, C는 모두 2,147,483,647 이하의 자연수
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

ll go(ll a, ll b) {
    if(b == 1) return a % c;
    ll ret = go(a, b/2);
    ret = (ret * ret) % c;
    if(b % 2) ret = (ret * a) % c; //홀수면 한번 더 곱해주기
    return ret;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    cout << go(a, b) << endl;

    return 0;

}