/*
題目：
https://leetcode.com/problems/coin-change/

解說：
先將硬幣由小至大排序，透過 DP 的方式紀錄目前能使用的硬幣，所排成的最小組合
從使用一個硬幣開始，逐步確認當使用該數量的硬幣時，能組成的最少數量為多少

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, INT_MAX/2);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++)
            {
                if(coins[j] > i) break;
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        if(dp[amount] == INT_MAX/2) return -1;
        return dp[amount];
    }
};