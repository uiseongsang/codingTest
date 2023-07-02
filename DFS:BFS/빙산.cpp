#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int n,m,a[304][304] ,ret = 0;
bool vis[304][304];

void bfs(int i, int j){
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

           if(ny < 0|| ny >= n|| nx < 0|| nx >= m || vis[ny][nx]) continue;

           if(a[ny][nx] == 0) {
               a[y][x] = (a[y][x] == 0) ? 0 : a[y][x]-1;
           }
           else {
               vis[ny][nx] = true;
               q.push({ny,nx});
           }
        }
    }
}

int solve(){
    while(true) {
        int ice = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0 && !vis[i][j]) {
                    vis[i][j] = true;
                    bfs(i,j);
                    ice++;
                }
            }
        }
        if(ice >= 2) return ret;
        if(ice == 0) return 0;
        memset(vis,0,sizeof(vis));
        ret++;
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    cout << solve();

    return 0;
}