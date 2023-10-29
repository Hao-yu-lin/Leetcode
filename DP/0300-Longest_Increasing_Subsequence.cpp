/*
題目：
https://leetcode.com/problems/longest-increasing-subsequence/

解說:

解法1：使用 DP
dp[i] 代表在 nums[i] 前的 lengthOfLIS 
dp[i] = max(dp[j]+1, dp[i]) 0 <= j < i and nums[i] > nums[j]
ans = max(dp)

解法2：使用 patience sorting

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<int> dp(n, 1);
        int curr_max = 1;

        for(int i = 1; i < n; ++i)
        {
            for(int j = 0; j < i; ++j)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);

            curr_max = max(curr_max, dp[i]);
        }
        return curr_max;
    }
};

class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        const int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp;

        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end())
                dp.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return dp.size();
    }
};
