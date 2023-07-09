#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
char a[104][104];
bool vis[104][104];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void dfs(int y, int x){
    vis[y][x] = true;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0|| ny >= n|| nx < 0|| nx >= n) continue;
        if(!vis[ny][nx] && a[y][x] == a[ny][nx]){
            dfs(ny,nx);
        }

    }
}

void solve(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j]) {
                dfs(i,j);
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }    

    // case 1
    memset(vis,false, sizeof(vis));
    solve();
    cout << cnt << " ";

    // case 2
    cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 'G') a[i][j] = 'R';
            else a[i][j] = a[i][j];
        }
    }
    memset(vis,false, sizeof(vis));

    solve();
    cout << cnt;

    return 0;
}