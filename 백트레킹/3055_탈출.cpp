#include <bits/stdc++.h>
using namespace std;
int R,C, ret = 0;
char a[51][51];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};
queue<pair<int,int>> biber;
queue<pair<int,int>> water;
pair<int,int> biber_house;

void test() {
    for(int i = 0; i < C; i++) {
        for(int j = 0; j < R; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

void bfs() {
    // 비버가 더 이상 이동할 수 없을떄 까지
    while(!biber.empty()) {
        // 물 확장
        int water_total = water.size();
        for(int i = 0; i < water_total; i++) {
            int water_y = water.front().first;
            int water_x = water.front().second;
            water.pop();

            for(int j = 0; j < 4; j++) {
                int next_water_y = water_y + dy[j];
                int next_water_x = water_x + dx[j];

                if((next_water_x >= 0 && next_water_x < C) && (next_water_y >= 0 && next_water_y < R) && a[next_water_y][next_water_x] != 'X' && a[next_water_y][next_water_x] != 'D') {
                    water.push({next_water_y, next_water_x});
                    a[next_water_y][next_water_x] = '*';
                }
            }
            cout << "water" << endl;
            test();
        }

        // 비버 이동
        int biber_total = biber.size();
        for(int i = 0; i < biber_total; i++) {
            int biber_y = biber.front().first;
            int biber_x = biber.front().second;

            biber.pop();

            for(int j = 0; j < 4; j++) {
                int next_biber_y = biber_y + dy[j];
                int next_biber_x = biber_x + dx[j];
                cout << next_biber_y << " : " << next_biber_x << endl;
                // 집이면 종료
                if((biber_house.first == next_biber_y) && (biber_house.second == next_biber_x))  {
                    ++ret;
                    cout << ret;
                    return;
                }

                if( (next_biber_x >= 0 && next_biber_x < C) && (next_biber_y >= 0 && next_biber_y < R) && a[next_biber_y][next_biber_x] != 'X') {
                    biber.push({next_biber_y, next_biber_x});
                    a[next_biber_y][next_biber_x] = 'S';
                }
            }
        }
        cout << "biber" << endl;
        test();
        ret++;
        cout << "count: " << ret << endl;
    }
    cout << "KAKTUS";
    return;
}

int main() {
    cin >> C >> R;
    string r;
    for(int i = 0; i < C; i++) {
        cin >> r;
        for(int j = 0; j < R; j++) {
            a[i][j] = r[j];
            if(a[i][j] == 'S') {
                biber.push({i,j});
            }
            else if( a[i][j] == '*') {
                water.push({i,j});
            }
            else if( a[i][j] == 'D') {
                biber_house.first = i;
                biber_house.second = j;
            }
        }
    }
    bfs();
    return 0;
}
