#include <bits/stdc++.h>
using namespace std;

const int dy_H[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dx_H[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy_M[] = {-1, 0, 1, 0};
const int dx_M[] = {0, -1, 0, 1};

int main() {
    int K, W, H;
    cin >> K >> W >> H;
    
    vector<vector<int>> board(H, vector<int>(W));
    vector<vector<vector<int>>> dist(H, vector<vector<int>>(W, vector<int>(K + 1, -1)));
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }
    
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, K});
    dist[0][0][K] = 0;
    
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int k = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int ny = y + dy_M[d];
            int nx = x + dx_M[d];
            
            if (ny >= 0 && ny < H && nx >= 0 && nx < W && board[ny][nx] == 0 && dist[ny][nx][k] == -1) {
                dist[ny][nx][k] = dist[y][x][k] + 1;
                q.push({{ny, nx}, k});
            }
        }
        
        if (k > 0) {
            for (int d = 0; d < 8; d++) {
                int ny = y + dy_H[d];
                int nx = x + dx_H[d];
                
                if (ny >= 0 && ny < H && nx >= 0 && nx < W && board[ny][nx] == 0 && dist[ny][nx][k - 1] == -1) {
                    dist[ny][nx][k - 1] = dist[y][x][k] + 1;
                    q.push({{ny, nx}, k - 1});
                }
            }
        }
    }
    
    int answer = -1;
    for (int k = 0; k <= K; k++) {
        if (dist[H - 1][W - 1][k] != -1) {
            if (answer == -1 || answer > dist[H - 1][W - 1][k]) {
                answer = dist[H - 1][W - 1][k];
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}
