#include<bits/stdc++.h>
using namespace std;

/**
 *  연결 컴포넌트를 구하는 dfs 
 */

const int n = 6;
vector<int> adj[n];
int visited[n];

void dfs(int u) {
    visited[u] = 1;
    cout << n << "\n";

    for(int v : adj[u]){
        if(visited[v] == 0) dfs(v);
    }   

    cout << u << " 로 부터 시작된 함수 종료";
    return;
}

