#include <bits/stdc++.h>
using namespace std;
int n,k;
bool vis[200004];
queue<pair<int,int>> q;

void solve(){
    q.push({n,0}); // 시작점
    vis[n] = true;

    while(!q.empty()){
        int pos = q.front().first;
        int retTime = q.front().second;
        q.pop();
        
        // underflow + overflow check
        if(pos < 0 || pos > 100000) continue;
        
        if(pos == k) {
            cout << retTime;
            break;
        }
        
        if(!vis[2*pos]){
            vis[2*pos] = true;
            q.push({2*pos,retTime+1});
        }

        if(!vis[pos-1]){
            vis[pos-1] = true;
            q.push({pos-1,retTime+1});
        }

        if(!vis[pos+1]){
            vis[pos+1] = true;
            q.push({pos+1,retTime+1});
        }

    } 
}

int main() {
    cin >> n >> k;
    solve();
    return 0;   
}