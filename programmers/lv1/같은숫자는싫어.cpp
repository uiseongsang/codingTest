#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> stk;
    vector<int> answer;

    for(auto it : arr) {
        if(stk.size() == 0) {
            stk.push(it);
        } else {
            if(stk.top() == it) continue;
            else stk.push(it);
        }
    }

    stack<int> tmp;
    while(!stk.empty()) {
        tmp.push(stk.top());
        stk.pop();
    }

    while(!tmp.empty()) {
        answer.push_back(tmp.top());
        tmp.pop();
    }

    return answer;
}

// 다른 사람 풀이
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> solution(vector<int> arr) 
// {

//     arr.erase(unique(arr.begin(), arr.end()),arr.end());

//     vector<int> answer = arr;
//     return answer;
// }