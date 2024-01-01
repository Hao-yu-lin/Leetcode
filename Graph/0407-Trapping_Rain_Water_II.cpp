/*
題目：
https://leetcode.com/problems/trapping-rain-water-ii/description/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

typedef vector<int> VI;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        const int m = heightMap.size();
        const int n = heightMap[0].size();

        priority_queue<VI, vector<VI>, greater<>> pq;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = 1;
                }
                    
        
        int ans = 0;
        int curr_h = INT_MIN;
        int dir[5] = {1, 0, -1, 0, 1};
        while(!pq.empty())
        {
            auto tmp = pq.top();
            int h = tmp[0], x = tmp[1], y = tmp[2];
            pq.pop();
           

            if(curr_h < h) curr_h = h;
            ans += curr_h - h;

            for(int k = 0; k < 4; k++)
            {
                int xx = x + dir[k];
                int yy = y + dir[k+1];
                if(xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                if(visited[xx][yy]) continue;
                visited[xx][yy] = 1;
                pq.push({heightMap[xx][yy], xx, yy});
            }
        }

        return ans;
    }
};