#include <bits/stdc++.h>
using namespace std;  
int y,x;
int sy = 0;
int sx = 0;
int y2 = 4;
int x2 = 4;
int visited[5][5];
int a[5][5] = {
    {1,0,1,0,1},
    {1,1,1,0,1},
    {0,0,1,1,1},
    {0,0,1,1,1},
    {0,0,1,1,1}
};
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    queue<pair<int, int>> q;

    visited[sy][sx] = 1; //방문 완료!
    q.push({sy,sx});
    
    
    while(q.size()) {
        tie(y,x) = q.front(); q.pop();

        cout << "q.front() = " << y << " q.pop() = " << x << "\n";

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];  
            int nx = x + dx[i]; 

            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5 || a[ny][nx] == 0 ) {
                continue;
            }
            // 방문한곳은 무시
            if(visited[ny][nx]) {
                continue;
            }

            // 방문도 안 하고, 갈수있으면(1이면) 큐에 추가! 
            // 큐에 순차적으로 넣기 떄문에 만약 막다른 길이 나오면 큐에서 제거하고 남아있는 큐를 사용하면 탐색!!
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            
            // continue는 여기로 이끈다.
        } 
    }
    
    cout << visited[y2][x2] << "\n";

    // debugging
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}