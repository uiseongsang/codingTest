#include <bits/stdc++.h>
using namespace std;
int n,a[26][26],cnt = 0;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
bool vis[26][26];
vector<int> v;

void dfs(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= n || vis[ny][nx] || a[ny][nx] == 0) continue;
        
        vis[ny][nx] = 1;
        cnt++;
        dfs(ny,nx);
    }
}

int main(){
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            a[i][j] = str[j] - '0';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1 && !vis[i][j]) {
				vis[i][j] = 1;
                cnt = 1;
                dfs(i,j);                            
				v.push_back(cnt);
            }
        }
    }

    sort(v.begin(),v.end());

    cout << v.size() << "\n";
    for(int i : v) {
        cout << i << "\n";
    }
    return 0;
}