/*
題目：
https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/

解說：
先將 queries 進行排序，由最小的 queries 開始擴展，如此換到較大的 queries 時就可以持續往下擴展，而不用重頭開始擴展

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) 
    {
        vector<pair<int, int>> qs;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < queries.size(); i++)
        {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        vector<int> ans(queries.size());
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int cnt = 0;
        int dir[5] = {1, 0, -1, 0, 1};
        for(auto [q, idx] : qs)
        {
            while(!pq.empty() && pq.top()[0] < q)
            {
                int x = pq.top()[1], y = pq.top()[2];
                pq.pop();
                cnt++;
                
                for(int i = 0; i < 4; i++)
                {
                    int xx = x + dir[i];
                    int yy = y + dir[i+1];
                    if(xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                    if(visited[xx][yy] == 1) continue;

                    pq.push({grid[xx][yy], xx, yy});
                    visited[xx][yy] = 1;
                }
            }
            ans[idx] = cnt;
        }
        return ans;
    }
};