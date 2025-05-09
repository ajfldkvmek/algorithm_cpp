
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;
int temp, result;

void go(int idx, int sum)
{
    if (result == 10)
        return; // backtracking -> 만족하는 조건을 안다면 그 조건에서 탐색을 종료시키기 위한 조건
    // -> 완전탐색 + 가지치기 - > 백트래킹
    if (idx == N)
    {
        result = max(result, (sum % 11));
        return;
    }
    go(idx + 1, sum + v[idx]);
    go(idx + 1, sum);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    go(0, 0);
    cout << result << "\n";

    return 0;
}