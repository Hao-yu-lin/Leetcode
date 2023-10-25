/*
題目：
https://leetcode.com/problems/house-robber/

解說：
考慮搶 與 不搶，當前的誰的效益最大。
搶的效益為 前前一個 + 當前
不搶的效益為 前一個

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[n-1];
    }
};