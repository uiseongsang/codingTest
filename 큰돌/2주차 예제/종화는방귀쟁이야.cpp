#include <bits/stdc++.h>
using namespace std;  
int ret;
bool visited[5][5];
int a[5][5] = {
    {1,0,1,0,1},
    {1,1,0,0,1},
    {0,0,0,1,1},
    {0,0,0,1,1},
    {0,1,0,0,0}
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void dfs(int y, int x) {
    
    visited[y][x] = true;
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 ) continue;
        if(a[ny][nx] == 1 && visited[ny][nx] == false) { 
            dfs(ny,nx);
        }
    }
}

int main() {

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(a[i][j] == 1 && !visited[i][j]) {
                ret++;
                dfs(i,j);
            }
        }
    }

    cout << "result: " << ret << "\n";

    return 0;
}