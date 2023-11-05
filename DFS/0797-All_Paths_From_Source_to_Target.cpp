/*
題目：
https://leetcode.com/problems/all-paths-from-source-to-target/

解說：
使用 DFS 尋找每一種可能

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        n = graph.size()-1;
        vector<int> path;
        dfs(0, path, graph);
        return ans;
    }

    void dfs(int curr, vector<int>& path, vector<vector<int>>& graph)
    {
        path.push_back(curr);
        if(curr == n)ans.push_back(path);
        else{
            for(const auto& next : graph[curr])
            {
                dfs(next, path, graph);
            }
        }
        path.pop_back();
    }
};