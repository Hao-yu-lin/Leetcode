/*
題目：
https://leetcode.com/problems/shortest-path-visiting-all-nodes/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        const int n = graph.size();
        const int keys = (1 << (n)) -1 ;
        queue<pair<int, int>> q;

        vector<vector<int>> visited(n, vector<int>(1 << n));
        for(int i = 0; i < n; i++) 
            q.push({i, 1 << i});

        int steps = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto p = q.front();
                q.pop();

                int node = p.first;
                int curr_keys = p.second;

                if(curr_keys == keys) return steps;
                if(visited[node][curr_keys]) continue;
                visited[node][curr_keys] = 1;
                for(int next : graph[node])
                    q.push({next, curr_keys | (1 << next)});
            }
            steps++;
        }
        return -1;
    }
};