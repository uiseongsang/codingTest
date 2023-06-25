#include <bits/stdc++.h>
using namespace std;
int n,m,ret=0;
string str;

int main(){
    cin >> n >> m;
    cin >> str;

    for(int i =0; i < m; i++) {
        int k = 0;
        if(str[i] == 'I'){
            while(str[i+1] == 'O' && str[i+2] == 'I') {
                k++;
                if(k == n){
                    ret++;
                    k--;
                }
                i+=2;
            }
            k=0;
        }
    }

    cout << ret;

    return 0;
}