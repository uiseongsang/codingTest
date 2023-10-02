#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void printV(vector<int> b) {
    for(int i : b) cout << i << " ";
    cout << "\n";
}

void combi(int start, vector<int> b) {
    if (b.size() == 6) { // 로또 번호는 6개를 선택해야 함
        printV(b);
        return;
    }
    for (int i = start + 1; i < n; i++) {
        b.push_back(v[i]);
        combi(i, b);
        b.pop_back();
    }
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) break;
        v.clear();
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        vector<int> b;
        combi(-1, b);
        cout << "\n";
    }
    
    return 0;
}
