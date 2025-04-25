#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> v;
vector<vector<int>> visited;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int landCount = 0;

// 맵의 크기는 N*Ms
// N(세로)과 M(가로)의 크기는 보두 1이상 100이하
// N*M 맵에서 1은 육지 0은 바다
// 이동 방향은 상하좌우로만 가능
// 연결된 육지의 수는?

void dfs(int y, int x) {

    if(y < 0 || x < 0 || y >= N || x >= M) return; // 범위체크
    if(visited[y][x] == 1) return; // 방문체크
    if(v[y][x] == 0) return; // 육지체크
    
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        dfs(ny, nx); // 연결된 육지 탐색
    }
}

int main(){

    cout << "N(세로) 길이 입력: ";
    cin >> N;
    cout << "M(가로) 길이 입력: ";
    cin >> M;

    // 크기 N x M으로 0으로 초기화
    v = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j ++){
            cin >> v[i][j];
        }
    }

    // 모든 셀을 시작점으로 고려
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(v[i][j] == 1 && visited[i][j] == 0) {
                dfs(i, j);
                landCount++; // DFS가 끝난 후 증가 (한 섬을 모두 탐색한 후)
            }
        }
    }

    cout << "발견된 대륙의 수: " << landCount << "\n";

    return 0;
    
}