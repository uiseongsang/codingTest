#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    int _size = nums.size()/2;
    int answer = 0;
    unordered_set<int> _set;
    
    for(int it : nums) _set.insert(it); 
    if(_size < _set.size()) answer = _size;
    else answer = _set.size();
     
    return answer;
}