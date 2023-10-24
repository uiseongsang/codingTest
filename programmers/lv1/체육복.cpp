#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes;
    clothes.assign(n,1);
    
    for(auto it : lost) clothes[it-1]--;
    for(auto it : reserve) clothes[it-1]++;
    
    for(int i = 0; i < n; i++) {
        if(clothes[i] == 0) { 
            if(i != 0 && clothes[i-1] == 2) {
                clothes[i]++;
                clothes[i-1]--;
            }
            else if(i != n-1 && clothes[i+1] == 2) {
                clothes[i]++;
                clothes[i+1]--;
            }
        }
    }
    
    for(auto it : clothes) {
        if(it != 0) {
            answer++;
        }
    }
    return answer;
}