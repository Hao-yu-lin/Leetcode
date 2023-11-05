/*
題目：
https://leetcode.com/problems/maximum-number-of-moves-in-a-grid

解說：
使用 DP 紀錄每一個走過的點他所到達的最大步數，搭配 DFS 進行搜索

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
    int m, n;
public:
    int maxMoves(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++)
        {
            int tmp = solve(grid, i, 0, 0, dp);
            ans = max(ans, tmp);
        }

        return ans-1;
    }

    int solve(vector<vector<int>>& grid, int i, int j, int prev, vector<vector<int>> &dp )
    {
        if(i < 0 || i >= m || j < 0 || j >= n) return 0;

        if(prev >= grid[i][j]) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int op1 = solve(grid, i-1, j+1, grid[i][j], dp);
        int op2 = solve(grid, i, j+1, grid[i][j], dp);
        int op3 = solve(grid, i+1, j+1, grid[i][j], dp);

        dp[i][j] = 1 + max(op1, max(op2, op3));
        return dp[i][j];
    }
};