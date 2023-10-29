/*
題目：
https://leetcode.com/problems/partition-equal-subset-sum/

解說：
這是 01 背包問題
01 背包問題典型公式
先考慮個數，再考慮容量

有使用到的觀念：
DP, 01 knapsack
*/

#include "../code_function.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0;
        for(const auto& c : nums){
            sum += c;
        }
        if(sum % 2 == 1) return false;
        else sum /= 2;

        vector<bool>dp(sum+1, false);
        dp[0] = true;
        
        for(int i = 0; i < nums.size(); i++)
        {
            auto dp2 = dp;
            for(int j = 0; j <= sum; j++)
            {
                if(j-nums[i] < 0) continue;
                if(dp2[j-nums[i]] == true)
                    dp[j] = true;
            }
        }
        return dp[sum];
    }
};
