//계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하
#include <bits/stdc++.h>
using namespace std;
int n,blue=0,white=0;
bool a[130][130];

void solve(int x, int y ,int size) {
    bool cut = false;
    int color = a[x][y];
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(color != a[i][j]){
                cut = true;
                break;
            }
        }
    }

    if(cut){
        solve(x,y, size/2); // 좌측 상단
        solve(x+size/2,y,size/2); // 우측 상단
        solve(x,y+size/2,size/2); // 좌측 하단
        solve(x+size/2,y+size/2,size/2); // 우측 하단
    } else {
        if(color == 1) blue++;
        else white++;
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }

    solve(0,0,n);

    cout << white << "\n";
    cout << blue << "\n";
    return 0;
}