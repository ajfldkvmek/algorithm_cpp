/**
 *  백준 17928
 *  오큰수
 *  A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1
 *  수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.
 *  input
 *  4
 *  3 5 2 7
 *
 *  output
 *  5 7 7 -1
 */
#include <bits/stdc++.h>
using namespace std;

int N, temp;
int a[1000004], b[1000004];
stack<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(b, -1, sizeof(b));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        while (s.size() && a[s.top()] < a[i])
        {
            b[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << b[i] << " ";
    }
}