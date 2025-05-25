/**
 *  백준 12851
 *  숨박꼭질
 */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

int visited[MAX + 4];
long long cnt[MAX + 4];

int main()
{
    int N, M;
    cin >> N >> M;
    if (N == M)
    {
        cout << "0\n1\n";
        return 0;
    }

    visited[N] = 1;
    cnt[N] = 1;

    queue<int> q;
    q.push(N);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, now * 2})
        {
            if (0 <= next && next <= MAX)
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                }
                else if (visited[next] == visited[now] + 1)
                {
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    cout << visited[M] - 1 << endl;
    cout << cnt[M] << endl;

    return 0;
}