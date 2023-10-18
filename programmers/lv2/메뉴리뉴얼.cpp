#include <bits/stdc++.h>

using namespace std;
unordered_map<string,int> combi[11];
int maxcnt[11];

void comb(string str, int cnt, string ret) {
        if(cnt == str.size()){
            int num = ret.size();
            combi[num][ret]++;
            maxcnt[num] = max(maxcnt[num],combi[num][ret]);
            return;
        }
    
    comb(str,cnt + 1, ret + str[cnt]);
    comb(str,cnt + 1, ret);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
   
    for(auto order : orders) {
        sort(order.begin(), order.end());
        comb(order,0,"");
    }
    
    for(auto num : course) {
        for(auto x : combi[num]) {
            if(x.second == maxcnt[num] && x.second >= 2) {
                answer.push_back(x.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}