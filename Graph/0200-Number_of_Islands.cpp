/*
題目：
https://leetcode.com/problems/number-of-islands/

解說：
針對每一個點判斷是否為 '1'，如果是 '1' 則對於該點進行 DFS

有使用到的觀念：
DFS
*/

#include "../code_function.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int count = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
            if(grid[i][j] == '1'){
                count++;
                dfs(grid, i, j);
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >=m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);

    }
private:
    int m;
    int n;
};
