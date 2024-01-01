/*
題目：
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

解說：
solution 1 是 O(n*k*target)
solution 2 是 O(target)

定義 dp[i][t] 是使用 i 個 dices 可以得到和為 t 的組合數
init: dp[0][0] = 1
dp[i][k] = sum(dp[i-1][t-j]) 1 <= j <= k

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
    int kMod = 1e9+7;
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                for(int t = j; t <= target; t++)
                {
                    dp[i][t] = (dp[i][t] + dp[i-1][t-j])%kMod;
                }
            }
        }

        return dp[n][target];
    }
};

class Solution2 {
    int kMod = 1e9+7;
public:
    int numRollsToTarget(int n, int k, int target) 
    {
        vector<int>dp(target+1, 0);

        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int t = target; t >= 0; t--)
            {
                dp[t] = 0;
                for(int j = 1; j <= k && j <= t; ++j)
                    dp[t] = (dp[t] + dp[t-j])%kMod;
            }
        }

        return dp[target];
    }
};