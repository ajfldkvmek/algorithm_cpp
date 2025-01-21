/*
    회문 만들기
    정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력
    알파벳 대문자로만 된 최대 50글자
*/
#include<bits/stdc++.h>
using namespace std;

string s, ret;
char mid;
int cnt[200], flag;


// TIP: 회문이 되기 위해서는 홀수개인 알파벳의 갯수가 0 or 1 이어야 한다
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 
    
    cin >> s;

    for(char c : s) cnt[c]++;

    for(int i = 'Z'; i >= 'A'; i--) {
        if(cnt[i]&1){
            //홀수인지 체크
            mid = char(i); 
            flag++;
            cnt[i]--;
        }
        if(flag == 2) break;
        for(int j = 0; j < cnt[i]; j+=2){
            ret = char(i) + ret;
            ret = ret + char(i);
        }
    }

    if(mid) ret.insert(ret.begin() + ret.size() / 2, mid);
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << ret << endl;

    return 0;

}