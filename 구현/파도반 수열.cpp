// #include <iostream>
// using namespace std;
// int t,n;
// long long a[101] = {0,1,1,};

// long long solve(int n) {
//     if(n < 3) {
//         return a[n];
//     }
//     else if(a[n] == 0) {
//         a[n] = solve(n-2) + solve(n-3);
//     }
//     return a[n];
// }

// int main() {
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         cout << solve(n) << "\n";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<long long> p;

void solve(int n) {
    p.resize(n);
    p[0] = p[1] = p[2] = 1;
    p[3] = p[4] = 2;

    for (int i = 5; i < n; i++) {
        p[i] = p[i - 1] + p[i - 5];
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        solve(n);

        cout << p[n - 1] << "\n";
    }
    return 0;
}