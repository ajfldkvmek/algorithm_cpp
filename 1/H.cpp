/*
    백준 2559
    연속적인 며칠 동안의 온도의 합이 가장 큰 값
    N: 1 ~ 10 만
    K: 1 ~ 10 만 사이에 포함되는 값이라면
    온도는 -100 ~ +100
    이 때 온도의 합이 최대가 되는 값 -> "구간합"
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, K, temp, psum[100001], ret = -10000004;

int main(){

    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> temp;
        psum[i] = psum[i-1] + temp;
    }

    for(int i = K; i <= N; i++){
        ret = max(ret, psum[i] - psum[i-K]);
    }

    cout << ret << endl;

   return 0;

}