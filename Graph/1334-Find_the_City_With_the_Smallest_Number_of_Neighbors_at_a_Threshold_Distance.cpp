/*
題目：
https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

解說：
為 Floyd 的模板題，使用 O(N^3) 時間，計算出任意兩點間的最短距離，再透過 O(N^2) 時間尋找答案

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        int dp[n][n];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; j++)
                dp[i][j] = INT_MAX/2;
        
        for(int i = 0; i < n; ++i) 
            dp[i][i] = 0;

        for(auto& p : edges)
        {
            int city1 = p[0], city2 = p[1], weights = p[2];
            dp[city1][city2] = weights;
            dp[city2][city1] = weights;
        }

        for(int city = 0; city < n; ++city)
        {
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; j++)
                {
                    int tmp = dp[i][city] + dp[city][j];
                    dp[i][j] = min(dp[i][j], tmp);
                }
        }

        int ans = -1;
        int curr_min = n+1;

        for(int i = 0; i < n; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n; j++)
            {
                if(i!=j && dp[i][j] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= curr_min)
            {
                curr_min = cnt;
                ans = i;
            }
        }
        return ans;
    }
};

