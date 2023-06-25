#include <bits/stdc++.h>
using namespace std;
//문제: 맥주 한 박스에는 맥주 20병이 있고, 이 박스에는 20개까지의 맥주만 담을 수 있다.
// 상근이는 페스티벌을 가는 길이고, 집에서 페스티벌까지 갈 때 50m마다 맥주 한 병씩 마실 예정이다.
// 상근이가 페스티벌까지 맥주가 바닥나지 않게 도착할 수 있는지 출력하는 문제이다.

// 출력: 상근이가 행복하게 페스티벌에 갈 수 있으면 happy, 맥주가 바닥나서 더 이상 이동할 수 없으면 sad 출력

int t,n;
bool vis[104];

struct point {
    int x, y;
};
point house,cu[104],festival;

bool bfs(int n) {
    
    return false;
}

int main(){
    cin >> t;
    // 편의점 없이 갈 수 있는 거리는 최대 50m * 20병 = 1000m
    while(t--) {
        fill(vis,vis*104, false);

        cin >> n;
        cin >> house.x >> house.y;
        for(int i = 0; i < n; i++){
            cin >> cu[i].x >> cu[i].y;
        }
        cin >> festival.x >> festival.y;

        bool ret = bfs(n);
        if(ret) cout << "happy\n";
        else cout << "sad\n";
    }
    return 0;
}