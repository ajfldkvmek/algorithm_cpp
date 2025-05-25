/**
 *  백준 12869 뮤탈리스크
 *
 *  뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격할 수 있다.
 *      1. 첫 번째로 공격받는 SCV는 체력 9를 잃는다.
 *      2. 두 번째로 공격받는 SCV는 체력 3을 잃는다.
 *      3. 세 번째로 공격받는 SCV는 체력 1을 잃는다.
 *
 *  SCV의 체력이 0 또는 그 이하가 되어버리면, SCV는 그 즉시 파괴된다. 한 번의 공격에서 같은 SCV를 여러 번 공격할 수는 없다.
 *  남아있는 SCV의 체력이 주어졌을 때, 모든 SCV를 파괴하기 위해 공격해야 하는 횟수의 최솟값
 *
 *  첫째 줄에 SCV의 수 N (1 ≤ N ≤ 3)이 주어진다. 둘째 줄에는 SCV N개의 체력이 주어진다. 체력은 60보다 작거나 같은 자연수이다.
 */

#include <bits/stdc++.h>
using namespace std;
int INF = 987654321;
int a[3], visited[64][64][64], N;
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3}};

struct A
{
    int a, b, c;
};
queue<A> q;

int bfs(int a, int b, int c)
{
    visited[a][b][c] = 1;
    q.push({a, b, c});
    while (q.size())
    {
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int na = max(0, a - _a[i][0]);
            int nb = max(0, b - _a[i][1]);
            int nc = max(0, c - _a[i][2]);

            if (visited[na][nb][nc])
                continue;

            visited[na][nb][nc] = visited[a][b][c] + 1;

            if (na == 0 && nb == 0 && nc == 0)
                return visited[na][nb][nc] - 1;

            q.push({na, nb, nc});
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << bfs(a[0], a[1], a[2]) << endl;

    return 0;
}