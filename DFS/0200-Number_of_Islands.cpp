/*
題目：
https://leetcode.com/problems/number-of-islands/

解說：
檢查每一個點，當遇到 1 時，開始進行 dfs 將周圍是 1 的數字全部換成 0。

有使用到的觀念：

*/

#include "../code_function.h"


class Solution {
    int m;
    int n;
    int dir[5] = {1, 0, -1, 0, 1};
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')return;
        grid[x][y] = '0';
        for(int i = 0; i < 4; i++)
        {
            dfs(grid, x+dir[i], y+dir[i+1]);
        }
    }
};
