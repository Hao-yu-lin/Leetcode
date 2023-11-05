/*
題目：
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

解說：
從 node 0 開始往向下延伸，題目有說明可以視為一顆 tree，因此不會有 loop 情形產生
從 0 開始向下延伸，[a, b] 時，將 a -> b 設為 cost 1，b -> a cost 設為 0

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        unordered_map<int, vector<pair<int, int>>> ump;

        for(auto& edge : connections)
        {   
            ump[edge[0]].push_back({edge[1], 1});  
            ump[edge[1]].push_back({edge[0], 0});
        }

        queue<int>q;
        vector<int> visited(n, 0);
        q.push(0);
        visited[0] = 1;
        int count = 0;

        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();

            for(const auto& next : ump[tmp])
            {
                if(visited[next.first] == 1) continue;
                q.push(next.first);
                visited[next.first] = 1;
                count += next.second;
            }
        }

        return count;
    }
};