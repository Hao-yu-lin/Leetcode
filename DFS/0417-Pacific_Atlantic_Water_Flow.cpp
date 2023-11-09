/*
題目：
https://leetcode.com/problems/pacific-atlantic-water-flow/

解說：
使用 DFS ，從海洋邊界逆游而上，
使用兩個 vector<vector<int>> 來標記 pac 與 atl 的流動情形

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int m, n;
    int dir[5] = {1, 0, -1, 0, 1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        m = heights.size();
        n = heights[0].size();

        if(m == 0) return {};
        // if(m==1 && n==1) return {1,1};

        vector<vector<bool>>pac(m, vector<bool>(n, false));
        vector<vector<bool>>atl(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++)
        {
            dfs(heights, i, 0, pac, heights[i][0]);
            dfs(heights, i, n-1, atl, heights[i][n-1]);
        }

        for(int j = 0; j < n; j++)
        {
            dfs(heights, 0, j, pac, heights[0][j]);
            dfs(heights, m-1, j, atl, heights[m-1][j]);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pac[i][j] && atl[i][j])ans.push_back({i, j});
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, int x, int y, vector<vector<bool>>& visited, int h)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true) return;
        if(h > heights[x][y]) return;
        visited[x][y] = true; 

        for(int i = 0; i < 4; i++)
        {
            dfs(heights, x+dir[i], y+dir[i+1], visited, heights[x][y]);
        }
    }
};