/*
題目：
https://leetcode.com/problems/number-of-enclaves/

解說：
從邊線延伸，將碰到的點都換成 0 ，最後計算是 1 的個數即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n-1);
        }

        for(int j = 0; j < n; j++)
        {
            dfs(grid, 0, j);
            dfs(grid, m-1, j);
        }

        int count = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) count++;

        return count;
    }

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return;
        grid[x][y] = 0;

        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }
};