#include <bits/stdc++.h>
using namespace std;
int t,n,b;
char a;
bool check[1000001];

void solve(){
    priority_queue<pair<int,int>> max_heap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a == 'I') {
            min_heap.push({b,i});
            max_heap.push({b,i});
            check[i] = true;
        }
        else if(a == 'D'){
            if(b == -1) {
                while(!min_heap.empty()) {
                    int tmp = min_heap.top().second;
                    if(check[tmp] == 1) break;
                    min_heap.pop();
                }
                if( min_heap.size() > 0) {
                    int tmp = min_heap.top().second;
                    check[tmp] = 0;
                }
            }
            else {
                while(!max_heap.empty()) {
                    int tmp = max_heap.top().second;
                    if(check[tmp] == 1) break;
                    max_heap.pop();
                }
                if( max_heap.size() > 0) {
                    int tmp = max_heap.top().second;
                    check[tmp] = 0;
                }
            }
        }
    }
    while(!min_heap.empty()) {
        int tmp = min_heap.top().second;
        if(check[tmp] == 1) break;
        min_heap.pop();
    }
    while(!max_heap.empty()) {
        int tmp = max_heap.top().second;
        if(check[tmp] == 1) break;
        max_heap.pop();
    }
    if(max_heap.empty() && min_heap.empty()) cout << "EMPTY\n";
    else cout << max_heap.top().first << " " << min_heap.top().first << "\n";
}

int main(){    
    cin >> t;
    while(t--) {
        cin >> n;
        solve();
    }
    return 0;    
}