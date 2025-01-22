#include<bits/stdc++.h>
using namespace std;

int n, m, a[15001], cnt;
void combi(int idx, vector<int> & v){

    if(v.size() == 2){
        int b = a[v[0]];
        int c = a[v[1]];
        if(b + c == m) cnt++;
        return;
    }
    for(int i = idx + 1; i < n; i++){
        v.push_back(i);
        combi(i,v); //다음 인덱스부터의 비교를 위한 재귀 호출
        v.pop_back();
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    combi(-1, v);
    cout << cnt << endl;

    return 0;
}