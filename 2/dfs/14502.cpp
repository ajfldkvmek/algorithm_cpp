/**
 *  백준 14502 연구소
 *  N * M 배열
 *  3 <= N, M <= 8
 *  0: 빈칸, 1: 벽, 2:바이러스
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int res; // 안전영역의 수
int visited[8][8];
int v[8][8];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

vector<pair<int, int>> virus;
vector<pair<int, int>> wall;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visited[ny][nx] == 1)
            continue;
        if (v[ny][nx] == 1)
            continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
}

int solve()
{
    fill(&visited[0][0], &visited[0][0] + 8 * 8, 0);

    for (pair<int, int> b : virus)
    {
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == 0 && !visited[i][j])
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 2)
                virus.push_back({i, j});
            if (v[i][j] == 0) // 벽 세울 빈칸 위치
                wall.push_back({i, j});
        }
    }

    for (int i = 0; i < wall.size(); i++)
    {
        for (int j = i + 1; j < wall.size(); j++)
        {
            for (int k = j + 1; k < wall.size(); k++)
            {
                v[wall[i].first][wall[i].second] = 1;
                v[wall[j].first][wall[j].second] = 1;
                v[wall[k].first][wall[k].second] = 1;
                res = max(res, solve());
                v[wall[i].first][wall[i].second] = 0;
                v[wall[j].first][wall[j].second] = 0;
                v[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << res << endl;
    return 0;
}