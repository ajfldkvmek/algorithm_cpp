#include <bits/stdc++.h>
using namespace std;

int N, cnt;

void solve(int N){
    cnt++;
    cout << cnt << endl;
    if(N == 0) return;
    for(int i = 0; i < 3; i++ ){
        solve(N-1);
    }
    return;
}

int main(){
    cout << "자연수 입력: ";
    cin >> N;
    solve(N);
    return 0;
}