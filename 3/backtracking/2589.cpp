/**
 *  백준 2589
 *  보물섬( N <= 50 )
 *  L은 육지 W는 물
 *  L로만 이동가능
 *
 *  무작위의 점 L1, L2 를 선택했을 때, L1-L2 로 이동하는 최단거리 중 가장 긴 거리 구하기
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, mx;
int visited[51][51];
char a[51][51];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void bfs(int y, int x)
{
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            if (visited[ny][nx])
                continue;
            if (a[ny][nx] == 'W')
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            mx = max(mx, visited[ny][nx]);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j] == 'L')
                bfs(i, j);
        }
    }

    cout << mx - 1 << "\n";
}
