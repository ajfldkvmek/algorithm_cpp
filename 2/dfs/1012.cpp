/**
 *  세로: N, 가로: M, 갯수: K
 *  M과 N은 각각 1이상 50이하, K는 1이상 2500 이하
 *  영역 구해서 최소 몇마리 지렁이 구입하면 될지 정하기
 *  지렁이가 이동할 수 있는 방향은 상하좌우 네 곳
 * 
 *  입력의 첫 줄에는 테스트 케이스의 갯수 T 가 주어짐
 *  첫 줄에는 가로M 과 세로N 의 길이가 주어짐 개수 K 가 주어짐
 *  그 뒤 배추가 심어진 개수 K줄 만큼 배추의 좌표가 주어짐
 *  그 다음 줄에는 배추의 위치가 주어짐
 *  
 *  connect component 문제
 */
#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int N, M, K, T;

vector<vector<int>> v, visited;
vector<int> result;

void dfs(int y, int x) {

    if(y < 0 || x < 0 || x >= M || y >= N) return; // 범위 벗어나면 리턴
    if(visited[y][x] == 1) return; // 이미 방문했으면 리턴
    if(v[y][x] == 0) return; // 배추 없으면 리턴

    visited[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(ny, nx);
    }

}

int main() {

    cin >> T; // 테스트 케이스

    for(int t = 0; t < T; t++){ // 테스트 케이스 수 만큼 반복
        int count = 0;
        cin >> M >> N >> K; // 가로, 세로 배추수

        v.clear();
        visited.clear();
        v.resize(N, vector<int>(M, 0)); // 배추심을 땅 전부 0으로 초기화
        visited.resize(N, vector<int>(M, 0)); // 방문 체크를 위해 전부 0으로 초기화
    
        for(int k = 0; k < K; k++) {
            int x, y;
            cin >> x >> y;
            v[y][x] = 1; // 배추를 심은  땅을 1로 
        }
    
        for(int n = 0; n < N; n++) {
            for(int m = 0; m < M; m++){
                if(v[n][m] == 1 && visited[n][m] == 0){
                    dfs(n, m);
                    count++;
                } 
            }
        }
        result.push_back(count);
    }

    for(int i : result)
        cout << i << endl;

    return 0;

}

