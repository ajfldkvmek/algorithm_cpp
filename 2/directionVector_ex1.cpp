#include<bits/stdc++.h>
using namespace std;

/**
 * 
 *  1, 0 으로 이루어진 3*3 행렬
 *  1 이면 방문 가능, 0이면 불가
 *  한 번 방문한 곳은 다시 방문하지 않음
 *  상하좌우 네 방향으로 한칸씩 이동가능
 *  시작점은 (0,0)
 *  갈수있는 지역은
 */

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int n = 3;
int v[n][n], visited[n][n];

void go(int y, int x){
    visited[y][x] = 1;
    cout << "x: " << x << ", y: " << y << '\n';
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 1. 경계조건 0이상 3미만
        // 2. 진행조건 해당지점의 값이 1인지 + 방문하지 않았는지
        if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
            if( v[ny][nx] == 1 && visited[ny][nx] == 0){
                go(ny, nx);
            }
        }
    }
}

int main() {

    // v 에 데이터 입력 받고
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    if(v[0][0] == 1) go(0, 0);
    else cout << "시작이 안된다";
}
