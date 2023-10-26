/*
題目：
https://leetcode.com/problems/jump-game-ii/

解說：
這邊使用 greedy，[left, right] 這區塊為目前該階段能跳的範圍距離

有使用到的觀念：
DP, Greedy
*/

#include "../code_function.h"

class Solution {
public:
    int jump(vector<int>& nums) 
    {
        const int n = nums.size();
        int ans = 0;
        int left = 0, right = 0;

        while(right < n-1){
            int farthest = 0;
            for(int i = left; i < right+1; i++){
                farthest = max(farthest, i + nums[i]);
            }
            left = right+1;
            right = farthest;
            ans ++;
        }
        return ans;
    }
};