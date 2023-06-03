#include <bits/stdc++.h>
using namespace std;
int n;
long long ret;
long long m = 1234567891;
string str;
int main() {
    cin >> n;
    char ch;

    long long r = 1;
    for(int i = 0; i < n; i++){
        cin >> ch;
        ret = ( ret + ((int)ch - 96) * r) % m;
        r = (r * 31) % m;
    }
    cout << ret;
    return 0;   
}