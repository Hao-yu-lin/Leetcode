/*
題目：
https://leetcode.com/problems/number-of-closed-islands/

解說：
先從邊界開始使用 DFS，將邊界延伸的陸地給用水填滿，0 -> 1
再從 i = [1...m-1], j = [1...n-1] 開始計算 islands 數目

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int m, n;

public:
    int closedIsland(vector<vector<int>>& grid) 
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
        for(int i = 1; i < m-1; i++)
            for(int j = 1; j < n-1; j++)
                {
                    if(grid[i][j] == 0){
                        count ++;
                        dfs(grid, i, j);
                    }
                }
        return count;
    }

    void dfs(vector<vector<int>>& grid, int x, int y)
    {
        if(x < 0 || x >= m || y < 0 || y >=n || grid[x][y] == 1)return;
        grid[x][y] = 1;
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }
};