/*
題目：
https://leetcode.com/problems/maximum-subarray/

解說：
nums[i] = max(nums[i], nums[i-1]+nums[i])
前一個點 (i-1) 紀錄的是，i-1 之前的 subarry 紀錄最大值，因此比較 max(nums[i], nums[i-1] + nums[i]) 

有使用到的觀念：
prefix sum
*/

#include "../code_function.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            nums[i] = max(nums[i], nums[i-1] + nums[i]);
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};