#include <bits/stdc++.h>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.length(); i++) {
        char tmp;
        int check = (int)s[i];
        if(s[i] == ' ') {
            answer += ' ';
            continue;
        }
        if( check >= 65 && check <= 90) {
            if(check + n > 90) {
                tmp = n + check - 90 + 64;
            } else {
                tmp =  check + n;
            }
        } else if(check >= 97 && check <= 122) {
            if(check + n > 122) {
                tmp = n + check - 122 + 96;
            } else {
                tmp =  check + n;
            }
        }
        answer += tmp;
    }
    return answer;
}
