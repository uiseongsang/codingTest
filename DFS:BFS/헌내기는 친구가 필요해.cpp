#include <bits/stdc++.h>
using namespace std;
int n,m, ret = 0;;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
char a[601][601];
bool vis[601][601];

void dfs(int y, int x) {
    vis[y][x] = true;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'X' || vis[ny][nx]) continue;
        if(a[ny][nx] == 'P') ret++;
        dfs(ny,nx);
    }
    
    return;
}

int main(){
    cin >> n >> m;
    int yy,xx;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'I') {
                yy = i;
                xx = j;
            }
        }
    }

    dfs(yy,xx);
    if(ret == 0) cout << "TT";
    else cout << ret;

    return 0;
}