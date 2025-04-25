/**
 *  안전영역 구하기
 *  가로 세로의 크기는 모두 N, N의 범위는 2이상 100이하의 정수
 *  각 영역에는 높이가 주어짐
 *  안전 영역의 갯수가 최대가 되는 강수량을 구하라
 */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v, visited;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0 ,1 ,0};
int N;

int minHeight = INT_MAX; 
int maxHeight = 0; 

int areaCount; 
int maxSafeArea = 0;

void dfs(int y, int x, int height){

    if(x < 0 || y < 0 || x>= N || y >= N) return;
    if(visited[y][x] == 1) return;
    if(v[y][x] <= height) return;

    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(ny, nx, height);
    }

}

int main(){

    cin >> N;
    v.resize(N, vector<int>(N));
 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> v[i][j];
            minHeight = min(minHeight, v[i][j]);
            maxHeight = max(maxHeight, v[i][j]);
        }
    }

    // min 부터 max 까지 반복해서 최대값 구하기
    for(int height = 0; height < maxHeight; height++) {
        visited.clear();
        visited.resize(N, vector<int>(N, 0));
        areaCount = 0;

        for(int y = 0; y < N; y++){
            for(int x = 0; x < N; x++){
                if(v[y][x] > height && visited[y][x] == 0){
                    dfs(y, x, height);
                    areaCount++;
                }
            }
        }
        maxSafeArea = max(maxSafeArea, areaCount);
    }

    cout << maxSafeArea << endl;

    return 0;

}
