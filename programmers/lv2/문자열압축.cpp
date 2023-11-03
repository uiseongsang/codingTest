#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    int answer = s.length();
    for(int i = 1; i <= s.length()/2; i++) {
        int cnt = 1;
        string tmp = "", a = "";
        a = s.substr(0,i);
        for(int j = i; j < s.length(); j+=i) {
            if(a == s.substr(j,i)) cnt++;
            else {
                if(cnt > 1) tmp += to_string(cnt);
                tmp += a;
                a = s.substr(j,i);
                cnt = 1;
            }
        }
        if(cnt > 1) tmp += to_string(cnt);
        tmp += a;
        if(answer > tmp.length()) answer = tmp.length();
    }
    return answer;
}