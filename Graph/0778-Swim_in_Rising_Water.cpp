/*
題目：
https://leetcode.com/problems/swim-in-rising-water/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int dir[5] = {-1, 0, 1, 0, -1};

        while(!pq.empty())
        {
            auto tmp = pq.top();
            pq.pop();
            int w = tmp[0];
            int x = tmp[1];
            int y = tmp[2];

            if(visited[x][y] == 1) continue;
            visited[x][y] = 1;
            ans = max(ans, w);
            if(x == n-1 && y == n-1) return ans;

            for(int i = 0; i < 4; i++)
            {
                int xx = x + dir[i];
                int yy = y + dir[i+1];
                if(xx<0 || xx>=n || yy<0 || yy>=n) continue;
                if(visited[xx][yy] == 1) continue;
                pq.push({grid[xx][yy], xx, yy});
            }
        }

        return -1;
    }
};