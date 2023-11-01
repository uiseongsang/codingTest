#include <bits/stdc++.h>
using namespace std;
int ret;

void dfs(vector<int> numbers, int x, int sumNum , int dept) {
    if(dept == numbers.size()) {
        if(sumNum == x) {
            ret++;
        }
        return;
    }
    dfs(numbers,x , sumNum + numbers[dept], dept+1);
    dfs(numbers,x, sumNum - numbers[dept], dept+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ret;
}