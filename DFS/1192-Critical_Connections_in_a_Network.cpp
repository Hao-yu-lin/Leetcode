/*
題目：
https://leetcode.com/problems/critical-connections-in-a-network/

解說：
本題考的是 Tarjan's algorithm。
在 DFS 中使用四個數組，
visited：因為是無向圖需使用 visited 紀錄是否拜訪過，
dfn：紀錄拜訪時的順序
low：初始化時為 low[node] = dfn[node]，紀錄 child 中能接觸到的最小時間點
parent：避免拜訪到 parent node

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<vector<int>> ans;
    int time = 0;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> edges(n);
        for(const auto p : connections)
        {
            edges[p[0]].push_back(p[1]);
            edges[p[1]].push_back(p[0]);
        }

        vector<bool>visited(n, false);
        vector<int>dfn(n, 0);
        vector<int>low(n, 0);
        vector<int>parent(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
                dfs(i, visited, dfn, low, parent, edges);
        }

        return ans;
    }

    void dfs(int node, vector<bool>& visited, vector<int>& dfn, vector<int>& low, vector<int>& parent, vector<vector<int>>& edges)
    {
        visited[node] = true;
        time ++;
        dfn[node] = low[node] = time;

        for(const int next : edges[node])
        {
            if(next == parent[node]) continue;

            if(!visited[next])
            {
                parent[next] = node;
                dfs(next, visited, dfn, low, parent, edges);

                if(low[next] > dfn[node]) ans.push_back({next, node});

                low[node] = min(low[node], low[next]);
            }else
            {
                low[node] = min(low[node], dfn[next]);
            }
        }
    }
};