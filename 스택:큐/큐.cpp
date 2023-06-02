#include <bits/stdc++.h>
using namespace std;
int t,n;
string str;
queue<int> q;
int main(){
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;
        if(str == "push") {
            cin >> n;
            q.push(n);
        }
        else {
            if(str == "pop") {
                if(!q.empty()){
                    cout << q.front() << "\n";
                    q.pop();
                }
                else cout << "-1" << "\n";
            }
            else if(str == "size") {
                cout << q.size() << "\n";
            }
            else if(str == "empty") {
                cout << q.empty() << "\n";
            }
            else if(str == "front") {
                if(!q.empty()){
                    cout << q.front() << "\n";
                }
                else cout << "-1" << "\n";
            }
            else if(str == "back") {
                if(!q.empty()){
                    cout << q.back() << "\n";
                }
                else cout << "-1" << "\n";
            }
        }
    }
    return 0;
}