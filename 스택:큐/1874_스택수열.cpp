#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
int n, cnt = 1;
vector<char> ret;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while(cnt <= x) {
            ret.push_back('+');
            stk.push(cnt);
            cnt++;
        }

        if(x == stk.top()) {
            stk.pop();
            ret.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }   
    }

    for (char result : ret) {
        cout << result << "\n";
    }

    return 0;
}