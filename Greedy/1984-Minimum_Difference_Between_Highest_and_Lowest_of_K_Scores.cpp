/*
題目：
https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        if(n <= k)
        {
            return nums[n-1] - nums[0];
        }
        int min_diff = INT_MAX;
        for(int i = n-1; i >= k-1; i--)
        {
            int diff = nums[i] - nums[i-k+1];
            min_diff = min(min_diff, diff);
        }

        return min_diff;
    }
};