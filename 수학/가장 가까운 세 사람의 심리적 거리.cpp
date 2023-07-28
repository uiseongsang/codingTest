#include <bits/stdc++.h>
#define MBTI_CNT 16
using namespace std;


int getDist(string a, string b, string c) {
    int dist = 0;
    for(int i = 0; i < a.size(); i++) {
        dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
    }
    return dist;
}

int solve(int n, vector<string> mbti) {
    if(n > MBTI_CNT * 2) return 0;

    int ret = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++) {
                ret = min(ret, getDist(mbti[i],mbti[j],mbti[k]));
            }
        }
    }
    return ret;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<string> mbti(n);
        for(int i = 0; i < n; i++) {
            cin >> mbti[i];
        }

        cout << solve(n, mbti) << "\n";
    }
    return 0;
}
