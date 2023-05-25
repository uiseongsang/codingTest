#include <bits/stdc++.h>
using namespace std;
int n,b;
string a;
stack<int> stk;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(a == "push") {
            cin >> b;
            stk.push(b);            
        }
        else {
            if(a == "top") {
                if(!stk.empty()) {
                    cout << stk.top() << "\n";                
                }
                else cout << "-1" << "\n";
            }
            else if (a == "size") {
                cout << stk.size() << "\n";
            }
            else if (a == "empty") {
                cout << stk.empty() << "\n";
            }
            else if( a == "pop") {
                if(!stk.empty()) {
                    cout << stk.top() << "\n";
                    stk.pop();
                }
                else cout << "-1" << "\n";
            }
        }
    }
    return 0;
}