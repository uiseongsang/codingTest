//https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int cnt = 0;

    int numIdenticalPairs(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) cnt++;
            }
            if(i == nums.size()-1) break;
        }
        return cnt;
    }
};