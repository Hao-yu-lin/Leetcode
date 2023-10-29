/*
題目：
https://leetcode.com/problems/maximal-square/

解說：
由左上往右下擴張尋找，
若(i,j)為 1 則，判斷其 (i-1, j-1), (i-1, j), (i, j-1) 是否 >= 1，如果都是 >= 1 代表可以擴張

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dp[i][j] = matrix[i-1][j-1] - '0';
                if(dp[i][j] == 0) continue;
                dp[i][j] = min( min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                
                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        }

        return ans;
    }
};