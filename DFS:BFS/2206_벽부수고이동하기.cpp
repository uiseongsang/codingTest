#include <bits/stdc++.h>
using namespace std;
int n,m, a[1004][1004], ret;
vector<vector<vector<int>>> dist;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void bfs() {
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while(!q.empty()) {
        int y,x,b;
        tie(y,x,b) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m ) continue;

            // 벽 부수지 않은 경우
            if(a[ny][nx] == 0 && dist[ny][nx][b] == -1) {
                dist[ny][nx][b] = dist[y][x][b] + 1;
                q.push({ny,nx,b});
            }

            // 벽 부수는 경우
            if(a[ny][nx] == 1 && b == 0 && dist[ny][nx][1] == -1) {
                dist[ny][nx][1] = dist[y][x][b] + 1;
                q.push({ny,nx,1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    dist.assign(n, vector<vector<int>>(m, vector<int>(2,-1)));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0'; // 문자를 숫자로 변환
        }
    }

    dist[0][0][0] = 1;

    bfs();
    
    if(dist[n-1][m-1][0] != -1 && dist[n-1][m-1][1] != -1) {
        ret = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    } else if(dist[n-1][m-1][0] != -1) {
        ret = dist[n-1][m-1][0];
    } else {
        ret = dist[n-1][m-1][1];
    }
    if(ret == -1) cout << "-1";
    else cout << ret;
    return 0;
}