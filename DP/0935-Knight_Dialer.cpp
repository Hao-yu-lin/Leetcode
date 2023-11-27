/*
題目：
https://leetcode.com/problems/knight-dialer/

解說：
dp[N][1] = dp[N-1][6]  + dp[N-1][8]
dp[N][2]
...
dp[N][0]

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int knightDialer(int n) 
    {
        vector<int> dp(10, 1);
        int M = 1e9+7;
        for(int i = 2; i <= n; i++)
        {
            auto dp_old = dp;
            dp[0] = dp_old[4] + dp_old[6];
            dp[1] = dp_old[6] + dp_old[8];
            dp[2] = dp_old[7] + dp_old[9];
            dp[3] = dp_old[4] + dp_old[8];
            dp[4] = (dp_old[3] + dp_old[9])%M + dp_old[0];
            dp[5] = 0;
            dp[6] = (dp_old[1] + dp_old[7])%M + dp_old[0];
            dp[7] = dp_old[2] + dp_old[6];
            dp[8] = dp_old[1] + dp_old[3];
            dp[9] = dp_old[4] + dp_old[2];

            for(int k = 0; k <= 9; k++)
                dp[k] %= M;
        }

        int ans = 0;

        for(int i = 0; i < 10; i++)
        {
            ans += dp[i];
            ans %= M;
        }

        return ans;
    }
};