//계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하
#include <bits/stdc++.h>
using namespace std;
int n, a[301], dp[301];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }
    // a[n] = n층 계단의 점수
    // dp[n] = n층 계단 까지의 최대값
    // dp[n] = dp[n-2] + a[n] vs dp[n-3] + a[n-1] + a[n]
    dp[0] = a[0];
    dp[1] = max(a[1], (dp[0] + a[1]));
    dp[2] = max(a[0] + a[2] , a[1] + a[2]);
    
    for(int i = 3; i < n; i++) {
        dp[i] = max( dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
    }
    
    cout << dp[n-1];
    return 0;
}