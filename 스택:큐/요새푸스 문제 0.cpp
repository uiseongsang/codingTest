#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n,k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }   
    
    cout << "<";

    while(n-- != 0){
        for(int i = 1; i <= k; i++){
            if(i == k) {
                cout << q.front();
                if(q.size() != 1) cout << ", ";
            }
            else {
                q.push(q.front());
            }
            q.pop();
        }
    }
    cout << ">";
    return 0;   
}