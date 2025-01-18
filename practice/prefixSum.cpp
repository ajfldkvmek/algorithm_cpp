#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    이런 구간합  쿼리의 경우
    누적합과 펜윅트리를 사용해서 문제를 풀어야한다.
    고정된 값들로 결과를 내기 위해서는 누적합을 사용하면되지만
    동적배열로 구성됐을 경우 누적합은 사용하지 못하기 때문에
    이 때 펜윅트리를 사용하면된다
*/
int a[100004], b, c ,psum[100004], n ,m;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //누적합을 저장하기위한 블록 : O(n)
    cout << "최댓값: ";
    cin >> n;
    cout << "반복횟수: ";
    cin >> m;
    for(int i = 1; i <= n; i++){
        //각 배열의 값들을 저장
        cin >> a[i];
        //이전 누적합들의 합과 새로 입력받은 값을 더해 새 누적합계산
        psum[i] = psum[i-1] + a[i];
    }

    //입력받은 b~c 구간에 해당하는 누적합을 구하기 위한 블록 O(1)
    for(int i = 0; i < m; i++){
        cout << "구간 b c 입력(c의 값은 b의 값보다 커야함니다)" << endl;
        cin >> b >> c;
        cout << psum[c] - psum[b-1] << endl;
    }
    return 0;
}
