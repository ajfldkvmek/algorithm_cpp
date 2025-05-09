/**
 *  백준 2636 치즈
 *  치즈가 모두 녹기까지의 시간
 */
#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, cnt2;
vector<pair<int, int>> v;
vector<vector<int>> visited, a;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

void bfs()
{
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx] == 1)
                continue;

            visited[ny][nx] = 1;
            if (a[ny][nx] == 1)
            {
                v.push_back({ny, nx});
            }
            else
            {
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    a.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        fill(&visited[0][0], &visited[0][0] + N * M, 0);
        v.clear();
        q.push({0, 0});
        visited[0][0] = 1;
        bfs();
        cnt2 = v.size();
        for (pair<int, int> b : v)
        {
            a[b.first][b.second] = 0;
        }
        bool flag = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (a[i][j] == 1)
                    flag = 1;
            }
        }
        cnt++;
        if (!flag)
            break;
    }

    cout << cnt << "\n"
         << cnt2 << "\n";
    return 0;
}