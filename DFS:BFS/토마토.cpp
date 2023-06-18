//계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하
#include <bits/stdc++.h>
using namespace std;
int m,n,h,ret=0,a[104][104][104];
const int dx[6] = {0,1,0,-1,0,0};
const int dy[6] = {-1,0,1,0,0,0};
const int dz[6] = {0,0,0,0,-1,1};
bool state = true;;
queue<pair<pair<int,int>,int>> q;

// void test(){
//     cout << "\n";
//     for(int i = 0; i < h; i++){
//         for(int j = 0; j < n; j++) {
//             for(int k = 0; k < m; k++){
//                 cout << a[i][j][k] << " ";
//             }
//             cout << endl;
//         }
        
//     }
// }

bool checkState()
{
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++){
                if(a[i][j][k] == 0) return false;
            }
        }
    }
    return true;
}

void bfs(){
    while(!q.empty()){
        int sizeQ = q.size();
        //cout << "size: " << sizeQ << endl;

        for(int currQ = 0; currQ < sizeQ; currQ++){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int z = q.front().second;
            q.pop();

            for(int i = 0; i < 6; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                int nz = dz[i] + z;

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) {
                    if(a[nz][ny][nx] == 0){
                        a[nz][ny][nx] = 1;
                        q.push(make_pair(make_pair(nx,ny),nz));
                    }
                }
            }

            if(q.empty()) {
                if(checkState()) {
                    cout << ret << "\n";;
                }
                else {
                    cout << -1 << "\n";;
                }
                return;
            }
        }
        // test();
        ret++;
    }
}

void solve(){
    if (state == true) {
        // 전부 1(익은 토마토) 일때 예외처리
        cout << 0 << "\n";
        return;
    }
    else if (q.empty()) { // 
    // 전브 0(안 익은 토마토) 일때 예외처리
        cout << -1 << "\n";
    }
    bfs(); // 전부 0 또는 1이 아닐 떄 BFS 들어감
}

int main(){
    cin >> m >> n >> h;

    // input
    for(int i = 0; i < h; i++){
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++){
                int tmp;
                cin >> tmp;
                a[i][j][k] = tmp;
                if(a[i][j][k] == 0 ) state = false; // 전부 1일 떄  처리용!
                if (a[i][j][k] == 1) q.push(make_pair(make_pair(k, j), i));
            }
        }
    }

    solve();

    return 0;
}