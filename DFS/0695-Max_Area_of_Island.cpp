/*
題目：
https://leetcode.com/problems/max-area-of-island/

解說：
透過 dfs 回傳周邊的面積

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();

        int max_island = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int tmp = dfs(grid, i, j);
                    max_island = max(max_island, tmp);
                }
            }

        return max_island;
    }

    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        int left = dfs(grid, x-1, y);
        int right = dfs(grid, x+1, y);
        int up = dfs(grid, x, y+1);
        int down = dfs(grid,x , y-1);

        return left + right + up + down + 1;
    }
};