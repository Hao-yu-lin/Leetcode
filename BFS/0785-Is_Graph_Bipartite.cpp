/*
題目：
https://leetcode.com/problems/is-graph-bipartite/

解說：
對於任意一個定點，將他歸納為 A 組，那與該點相鄰的點必定都要歸入 B，而該點相鄰的點其相鄰點會被歸入為 A 組。
因此從 node 0 開始做 BFS 遍歷，擴展時 A/B組交替標記。
如果在標記過程中遇到已經分組的節點，檢查是否有矛盾之處，比如接續要標記 A 但已經被標記成 B，此處就是矛盾之處，如果有就返回False

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        const int n = graph.size();
        vector<int> visited(n, -1);

        for(int i = 0; i < n; i++)
        {
            if(visited[i] != -1) continue;

            queue<pair<int, int>> q;
            q.push({i, 0}); // {node, group}

            visited[i] = 0;

            while(!q.empty())
            {
                int node = q.front().first;
                int group = q.front().second;
                q.pop();

                for(const auto next : graph[node])
                {
                    if(visited[next] != -1)
                    {
                        if(visited[next] != 1-group) return false;
                    }else
                    {
                    visited[next] = 1-group;
                    q.push({next, 1-group});
                    }
                }
            }
        }
        return true;
    }
};