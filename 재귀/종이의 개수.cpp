#include <bits/stdc++.h>
using namespace std;
int n,a[2200][2200],ret[3];

bool check(int x, int y, int num){
    int start = a[x][y];
    for(int i = x; i < x + num; i++){
        for(int j = y; j < y + num; j++) {
            if(start != a[i][j]) return false;
        }
    }
    return true;
}

void solve(int x, int y, int num){
    if(check(x,y,num)){
        ret[a[x][y]]++;
    }
    else {
        int newSize = num / 3; // 새로운 사이즈
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) {
                solve(x+newSize*i, y+newSize*j, newSize);
            }
        }

    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            a[i][j] = ++tmp;
        }
    }    

    solve(0,0,n);
    cout << ret[0] << "\n"; 
    cout << ret[1] << "\n";
    cout << ret[2] << "\n";
    return 0;   
}