#include <bits/stdc++.h>
using namespace std;
int f,s,g,u,d;
bool vis[1000004];
queue<pair<int,int>> q;

int solve(){
    q.push({s,0});
    while(!q.empty()){
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == g) {
            return cnt;
        }   

        if(cur + u <= f) {
            if (!vis[cur + u]) {
                vis[cur + u] = true;
                q.push(make_pair(cur + u, cnt + 1));
            }
        }

        if(cur - d >= 1) {
            if (!vis[cur - d]) {
                vis[cur - d] = true;
                q.push(make_pair(cur - d, cnt + 1));
            }
        }
    }
    return -1;
}

int main(){    
    cin >> f >> s >> g >> u >> d;
    
    int ret = solve();

    if(ret == -1) {
        cout << "use the stairs";
    } else {
        cout << ret;
    }
    
    return 0;    
}