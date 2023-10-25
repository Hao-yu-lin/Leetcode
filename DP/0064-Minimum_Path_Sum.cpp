/*
題目：
https://leetcode.com/problems/minimum-path-sum/

解說：
使用 dp 紀錄每一點的最小值，最小值計算方式為取 min{左邊,上面} + 該點

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX/2));

        dp[0][0] = grid[0][0];

        for(int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j = 1; j < n; j++)
        {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }

        return dp[m-1][n-1];
    }
};