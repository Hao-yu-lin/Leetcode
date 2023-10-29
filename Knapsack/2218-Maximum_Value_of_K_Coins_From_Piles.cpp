/*
題目：
https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

解說：
dp[i][j] the maximum total value of coins by the first i piles and choosing j coins

suppose we choose t coins in the i-th pile
dp[i][j] = max{dp[i-1][j-t]+pilesPreSum[i][t]} for t = 0,1, 2... len(piles[i])

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
    int dp[1003][2003];
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        const int n = piles.size();
        vector<vector<int>> presum(n);
        for(int i = 0; i < n; i++)
        {   
            int sum = 0;
            presum[i].push_back(sum);
            for(int j = 0; j < piles[i].size(); j++)
            {
                sum += piles[i][j];
                presum[i].push_back(sum);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                dp[i][j] = 0;
                for(int t = 0; t <= min(j, (int)piles[i].size()); t++)
                {
                    dp[i][j] = max(dp[i][j], (i==0?0:dp[i-1][j-t])+presum[i][t]);
                }
                
            }
        }

        return dp[n-1][k];
    }
};