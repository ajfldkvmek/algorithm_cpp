#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int visited[4];
vector<int> adj[4];

void print()
{
    for (int i : v)
    {
        cout << char(i + 'A') << " ";
    }
    cout << "\n";
}

void go(int idx)
{
    if (v.size() == 3)
    {
        print();
        return;
    }
    for (int there : adj[idx])
    {
        if (visited[there] == 1)
            continue;
        visited[there] = 1;
        v.push_back(there);
        go(there);          // 재귀호출
        visited[there] = 0; // 방문노드 -> 미방문으로 변경
        v.pop_back();       // 방문여부 변경 후 해당 인덱스 pop
    }
}

int main()
{
    // 양방향 간선추가
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3);
    adj[3].push_back(1);

    visited[0] = 1;
    v.push_back(0);
    go(0);
    return 0;
}
