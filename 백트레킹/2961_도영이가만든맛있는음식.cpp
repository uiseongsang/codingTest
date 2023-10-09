#include <bits/stdc++.h>
using namespace std;
int N,S,B, ret = 987654321;
vector<pair<int,int>> _vec;

void solve(vector<int> b){
    int val1, val2;
    val1 = 1;
    val2 = 0;

    for(int i : b) {
        val1 *= _vec[i].first;
        val2 += _vec[i].second;
    }
    ret = min(ret, abs(val1 - val2));
}

void combi(int start, vector<int> b) {
    if( b.size() > 0) {
        solve(b);
    }

    for(int i = start + 1; i < N; i++) {
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> S >> B;
        _vec.push_back({S,B});
    }
    
    vector<int> b;
    combi(-1,b);

    cout << ret;
    return 0;
}