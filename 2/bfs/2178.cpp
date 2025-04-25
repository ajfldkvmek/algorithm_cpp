/**
 *  N * M
 *  가중치가 모두 같은 경우 최단거리 -> bfs
 *  출발: (1, 1)
 *  도착: (N, M)
 *  칸을 셀 때는 시작과 도착도 포함
*/
#include<bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M;

vector<vector<int>> v, visited;

int bfs(){
    // 시작: {1, 1}, 종료: {N, M}
    queue<pair<int, int>> q; 
    q.push({1,1});

    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();

        if(ny == N && nx == M){
            return visited[ny][nx];
        }

        for(int i = 0; i < 4; i++){
            int x = nx + dx[i];
            int y = ny + dy[i];

            if(x >= 1 && x <= M && y >= 1 && y <= N && v[y][x] == 1 && visited[y][x] == 1){
                q.push({y, x});
                visited[y][x] = visited[ny][nx] + 1;
            }
        }
    }

    return -1; // 도착할 수 없을 때

}

int main(){

    cin >> N >> M;
    v.resize(N+1, vector<int>(M+1));
    visited.resize(N+1, vector<int>(M+1, 1));

    string line;
    for(int i = 1; i <= N; i++){
        cin >> line;
        for(int j = 1; j <= M; j++){
            v[i][j] = line[j-1] - '0';
        }
    }

    int result = bfs();
    if(result == -1) cout << "도착못해요" << endl;
    else cout << result << '\n';

    return 0;
}