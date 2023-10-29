/*
題目：
https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/

解說：

解法一：
使用 take no not 的概念，搭配 recursion
dp[i][target] 第 i 位置時，可以形成 target 的數列長度為多少，如果是 invalid 則設定為 -1001

如果 take ， 此時 taret = taret - nums[i]，繼續往下配對
如果 not take ， 此時 target 不變，繼續往下配對

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(1001, vector<int>(1001, -1));
        int ans = takeornot(nums, 0, target);
        return (ans > 0) ? ans : -1;
    }

    int takeornot(vector<int>& nums, int i, int target)
    {
        if(target == 0) return 0;
        if(target < 0 || i >= nums.size()) return -1001; // invalid case
        if(dp[i][target] != -1) return dp[i][target];

        int take = 1 + takeornot(nums, i+1, target-nums[i]);
        int notake = takeornot(nums, i+1, target);

        dp[i][target] = max(take, notake);
        return dp[i][target];
    }
};