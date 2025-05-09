/**
 *  백준 1325
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int a, b;
vector<int> v[10001];
int visited[10001], mx, dp[10001];
int dfs(int here)
{
    int ret = 1;
    for (int i : v[here])
    {
        if (visited[i])
            continue;
        visited[i] = 1;
        ret += dfs(i);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    while (M--)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        memset(visited, 0, sizeof(visited));
        visited[i] = 1;
        dp[i] = dfs(i);
        mx = max(dp[i], mx);
    }

    for (int i = 1; i <= N; i++)
    {
        if (mx == dp[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}