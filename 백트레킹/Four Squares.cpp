#include <bits/stdc++.h>
using namespace std;
int n, a[500001];

int solve(int n) {
    if(n <= 1) return n;
    else {
        if(a[n] == -1) {// 메모이제이션 기록 확인
            int ret = INT_MAX;
            for(int i = pow(n,0.5); i >= 1; i--) {
                ret = min(ret, 1 + solve(n - pow(i,2)));
            }
            a[n] = ret;
            return ret;
        }
        else return a[n];
    }
}

int main(){
    cin >> n;

    fill(a,a+50001, -1);

    cout << solve(n);

    return 0;
}