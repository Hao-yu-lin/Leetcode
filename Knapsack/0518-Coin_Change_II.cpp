/*
題目：
https://leetcode.com/problems/coin-change-ii/

解說：
這是 01 背包問題

原始概念如下
for i in coins -----> 使用 coins[0 : i]
    for c in amount -----> 組合成 amount = c 的情形
        dp[c] = 0;
        for(int k = 0; k <= c/coins[i]; k++)
            dp[i][c] += dp[i-1][c-k*coins[i]] 
        

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;

        for(int i = 0; i < coins.size(); i++)
        {
            for(int c = 1; c <= amount; c++)
            {
                if(c >= coins[i])
                    dp[c] += dp[c-coins[i]];
            }
        }

        return dp[amount];
    }
};