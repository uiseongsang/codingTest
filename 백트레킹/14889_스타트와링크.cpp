#include <bits/stdc++.h>
using namespace std;
int n, a[22][22], ret = 987654321;
bool check[22];

void solve(int x, int pos) {
    // 카운트수가 정원의 1/2
    if( x == n / 2) {
        int start, link;
        start = link = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(check[i] == true && check[j] == true) start += a[i][j];
                if(check[i] == false && check[j] == false) link += a[i][j];
            }
        }

        int tmp = abs(start - link);
        ret = min(ret,tmp);
        return;
    }

    for(int i = pos; i < n; i++) {
        check[i] = true;
        solve(x+1, i+1);
        check[i] = false;
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }   

    solve(0,0);
    cout << ret;
    return 0;
}
