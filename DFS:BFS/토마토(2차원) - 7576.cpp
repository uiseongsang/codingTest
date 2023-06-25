#include <bits/stdc++.h>
using namespace std;
int m,n,a[1004][1004];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int cnt[2];
queue<pair<int,int>> q;

void test(){
    cout << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;       
    }
}

int solve(){
    // 익은 토마토 즉,1이 없을 떄 
    if(cnt[1] == 0) return -1;
    
    int ret = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        
        q.pop();
        
        //test();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
        
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        
            if(a[ny][nx] == 0) {
                cnt[0]--;
                a[ny][nx] = a[y][x] + 1;
                ret = a[ny][nx]-1;
                q.push({nx,ny});
            }
        }    
    }
    if(cnt[0] != 0) {
        // 0이 남아 있을 떄
        return -1;
    } else{
        return ret;
    }
}

void input(){
    cin >> m >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] != -1) cnt[a[i][j]]++; // cnt[0] = 0 갯수, cnt[1] = 1의 갯수
            if(a[i][j] == 1) q.push({j,i});
        }
    }
}

int main(){    
    input();
    
    cout << solve();
    
    return 0;    
}
