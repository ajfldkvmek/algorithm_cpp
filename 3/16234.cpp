/**
 *  백준 16234
 *  N * N 의 크기 1 <= N <= 50
 *  국경선을 공유하는 두 나라의 인구차가 L명 이상 R명 이하라면 국경선을 하루 연다
 *  이 조건에 의해 국경선이 모두 열렸다면 인구이동 시작 그 나라들을 하루동안 연합이라고 함
 *  연합을 이루는 각 칸의 인구수는 (연합의 인구수) / (칸의 수) - 소수점은 버린다
 *  1 <= L <= R <= 100
 *
 *  이동이 완료되면 연합을 해체하고 국경선을 닫는다.
 *
 *  인구 이동이 며칠동안 발행하는 지 구하시오
 *
 */

#include <bits/stdc++.h>
using namespace std;
int visited[51][51], a[51][51], N, L, R, sum, cnt;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};
vector<pair<int, int>> v;

void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[ny][nx])
            continue;

        int diff = abs(a[y][x] - a[ny][nx]);
        // 양 국의 인구차이가 L과 R 사이일때만
        if (diff >= L && diff <= R)
        {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
            sum += a[ny][nx];
            dfs(ny, nx);
        }
    }
}

int main()
{

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }

    while (true)
    {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j])
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({i, j});
                    sum = a[i][j];
                    dfs(i, j);
                    if (v.size() == 1)
                        continue;
                    int avg = sum / v.size();
                    for (pair<int, int> p : v)
                        a[p.first][p.second] = avg;

                    flag = 1;
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}