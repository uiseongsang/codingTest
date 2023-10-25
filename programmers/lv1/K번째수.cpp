// 내코드
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> tmp : commands) {
        int i,j,k;
        i = tmp[0];
        j = tmp[1];
        k = tmp[2];
        
        vector<int> v;
        for(int x = 1; x <= array.size(); x++) {
            if(x >= i && x <= j) {
                v.push_back(array[x-1]);
            }
        }
        sort(v.begin(), v.end());
        answer.push_back(v[k-1]);
    }
    return answer;
}

// 다른 사람 코드
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}
*/