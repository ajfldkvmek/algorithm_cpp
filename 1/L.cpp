#include<bits/stdc++.h>
using namespace std;

int n, m, a[15001], cnt;
int main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++){
            if(a[i] + a[j] == m) cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}