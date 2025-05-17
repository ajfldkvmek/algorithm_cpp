/**
 * #: 벽
 * .: 지나갈 수 있는 공간
 * J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
 * F: 불이 난 공간
 *
 * 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로 이동
 * 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
 * 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
 * 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수
 *
 */
#include <bits/stdc++.h>
using namespace std;
int INF = 987654321;

char a[1004][1004];
int R, C, sx, sy;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int ret, x, y;

int fire_check[1004][1004], person_check[1004][1004];

bool in(int a, int b)
{
    return 0 <= a && a < R && 0 <= b && b < C;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<pair<int, int>> q;
    cin >> R >> C;
    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'F')
            {
                fire_check[i][j] = 1;
                q.push({i, j});
            }
            else if (a[i][j] == 'J')
            {
                sy = i;
                sx = j;
            }
        }
    }

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop(); // c++에서는 자바의 poll/remove 와 다르게 반환값이 없음
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!in(ny, nx))
                continue; // 범위 체크
            if (fire_check[ny][nx] != INF || a[ny][nx] == '#')
                continue;
            fire_check[ny][nx] = fire_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // 지훈이 위치 초기화
    person_check[sy][sx] = 1;
    q.push({sy, sx});

    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        // 가장자리(탈출)
        if (x == C - 1 || y == R - 1 || x == 0 || y == 0)
        {
            ret = person_check[y][x];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!in(ny, nx))
                continue;
            if (person_check[ny][nx] || a[ny][nx] == '#')
                continue;
            if (fire_check[ny][nx] <= person_check[y][x] + 1) // 불이 덜 빨리 번지면 진행 불가
                continue;
            person_check[ny][nx] = person_check[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if (ret)
    {
        cout << ret << endl;
    }
    else
    {
        cout << "IMPOSSIBLE \n";
    }

    return 0;
}