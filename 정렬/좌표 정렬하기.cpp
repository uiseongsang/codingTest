#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<pair<int,int>> v;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second; // y가 작은 순으로 정렬
    return a.first < b.first; // x좌표가 작은순으로 정렬
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(),cmp);
    for( auto it : v) {
        cout << it.first << " " << it.second << "\n";
    }
    return 0;   
}