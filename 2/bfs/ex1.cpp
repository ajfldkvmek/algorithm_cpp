#include<bits/stdc++.h>
using namespace std;

// 최단거리 구하기
// 상하좌우로 움직일 수 있음
// 1이면 이동가능 0이면 불가
// 세로N 가로M 모두 1에서 100사이의 값
// 최단거리를 구해라
// 시작위치와 도착위치가 주어짐

int N, M; // 세로, 가로 크기
int sy, sx, fy, fx; // 시작 위치(y, x)와 도착 위치(y, x)
vector<vector<int>> v; // 맵 정보 저장
vector<vector<int>> visited; // 거리 정보 저장 (visited 대신 dist로 변경)

// 상하좌우 이동을 위한 방향 벡터
int dy[] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dx[] = {0, 0, -1, 1};

int bfs() {
    queue<pair<int, int>> q; // pair<y, x> 형태로 좌표 저장
    
    q.push({sy, sx});
    visited[sy][sx] = 1;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        // 도착점에 도달한 경우
        if (y == fy && x == fx) {
            return visited[y][x];
        }
        
        // 상하좌우 이동
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 맵 범위 내에 있고, 아직 방문하지 않았으며, 이동 가능한 칸인 경우
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && visited[ny][nx] == 0 && v[ny][nx] == 1) {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    
    return -1; // 도착점에 도달할 수 없는 경우
}

int main() {
    cin >> N >> M;
    
    // 맵과 거리 배열 초기화
    v.resize(N, vector<int>(M));
    visited.resize(N, vector<int>(M, 0));
    
    // 시작점과 도착점 입력
    cin >> sy >> sx;
    cin >> fy >> fx;
    
    // 맵 정보 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    
    // BFS 실행하여 최단 거리 계산
    int result = bfs();
    cout << result << endl;
    
    return 0;
}
