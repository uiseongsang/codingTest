#include <bits/stdc++.h>
using namespace std;
int n,k;

int solve(vector<int> &v ){
    sort(v.begin(), v.end(), greater<int>());

    int ret = 0;
    for(int i = 0 ; i < n; i++) {
        if(k >= v[i]) {
            ret += k / v[i];
            k %= v[i];
        }
    }
    return ret;
}

int main() {
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    } 

    cout << solve(v);;
    return 0;
}