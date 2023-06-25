#include <bits/stdc++.h>
using namespace std;
int t;
deque<int>  dq;

int main(){
    cin >> t;
    while(t--){
        bool isReverse = false;
        bool isError = false;
        int n;
        string str,input,s = "";

        cin >> str;
        cin >> n;
        cin >> input;
        
        // 배열 인풋 전처리
        for (int i = 0; i<input.length();i++) {
            if (isdigit(input[i])) {
                s += input[i];
            }
            else {
                if (!s.empty()) {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }
        }

        // RD 실행
        for(auto i : str) { 
            if(i == 'R') {
                if(isReverse) {
                    isReverse = false;
                }
                else {
                    isReverse = true;
                }
            }
            else if(i == 'D'){
                if(dq.empty()){
                    isError = true;
                    break;
                }
                if(isReverse) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }    
            }
        }
        
        // 출력
        if(isError) {
            cout << "error" << "\n";
        }
        else {
            cout << "[";
            while(!dq.empty()){    
                if(isReverse){
                    cout << dq.back();
                    dq.pop_back();
                }
                else {
                    cout << dq.front();
                    dq.pop_front();
                }

                if(!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}