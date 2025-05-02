#include <bits/stdc++.h>
using namespace std;

/**
 *  백준 3473번
 *  N! 의 0의 개수를 출력하는 프로그
 *  첫 번째 줄에 테스트 케이스의 개수 T가 주어진다트
 *  각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다.
 *  1 <= N <= 10^9
 *  각 테스트 케이스에 대해 N!의 0의 개수를 출력한다.
 */

int T, N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        int ret2 = 0, ret5 = 0;
        for (int r2 = 2; r2 <= N; r2 *= 2)
        {
            ret2 += N / r2;
        }
        for (int r5 = 5; r5 <= N; r5 *= 5)
        {
            ret5 += N / r5;
        }
        cout << min(ret2, ret5) << "\n";
    }

    return 0;
}
