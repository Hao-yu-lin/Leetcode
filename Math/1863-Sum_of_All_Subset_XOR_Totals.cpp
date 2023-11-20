/*
題目：
https://leetcode.com/problems/sum-of-all-subset-xor-totals/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int ans;
    int n;
public:
    int subsetXORSum(vector<int>& nums) 
    {
        ans = 0;
        n = nums.size();
        for(int i = 0; i < n; i++)
        {
            recursion(nums, i, 0);
        }
        return ans;
    }

    void recursion(vector<int>& nums, int idx, int val)
    {
        if(idx >= n) return;
        val ^= nums[idx];
        ans += val;
        for(int i = idx+1; i < n; i++)
        {
            recursion(nums, i, val);
        }
    }
    
};