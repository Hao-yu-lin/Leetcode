/*
題目：
https://leetcode.com/problems/count-number-of-ways-to-place-houses/

解說：
dp[i][0] = (dp[i-1][1] + dp[i-1][0])%kMod;
dp[i][1] = dp[i-1][0];

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    long long dp[10005][2];
    long long kMod = 1e9+7;
public:
    int countHousePlacements(int n) 
    {
        dp[1][0] = 1;   
        dp[1][1] = 1;   

        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = (dp[i-1][1] + dp[i-1][0])%kMod;
            dp[i][1] = dp[i-1][0];
        }

        long long result = (dp[n][0] + dp[n][1])%kMod;

        return (result * result)%kMod;
    }
};