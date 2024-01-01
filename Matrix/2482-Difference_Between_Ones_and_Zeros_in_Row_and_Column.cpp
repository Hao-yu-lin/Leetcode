/*
題目：
https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

解說：
解法1：
假設 i rows 有 x 個 1 與 j cols 有 y 個 1 
x + y - (m-x) - (n-y)
= x + y - m + x - n + y
= 2x + 2y - m - n

解法2：
若 grid[i][j] == 1 時 rows[i]++, cols[j]++ 
若 grid[i][j] == 0 時 rows[i]--, cols[j]--

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int>> diff(m, vector<int>(n, -(m+n)));
        vector<int> onerows(m, 0);
        vector<int> onecols(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    onerows[i]++;
                    onecols[j]++;
                }
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                diff[i][j] += 2*onerows[i] + 2*onecols[j];
            }

        return diff;
    }
};

class Solution2 {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        const int m = grid.size();
        const int n = grid[0].size();
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        vector<int> onerows(m, 0);
        vector<int> onecols(n, 0);

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    onerows[i]++;
                    onecols[j]++;
                }else
                {
                    onerows[i]--;
                    onecols[j]--;
                }
            }
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                diff[i][j] = onerows[i] + onecols[j];
            }

        return diff;
    }
};

