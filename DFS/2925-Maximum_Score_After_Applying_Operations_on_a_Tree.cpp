/*
題目：
https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/

解說：
解題關鍵在於，要得到最大 score 必須最小化整條路徑的值，比較每一個 node 值與該子樹之間誰比較小，取較小的
透過 DFS 方式遍歷每一個可能情形，返回該點的最小值。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) 
    {
        const int n = values.size();

        vector<vector<int>> adj(n);
        for(const auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        auto p = dfs(0, -1, adj, values);
        return p.second - p.first;
    }

    pair<long long, long long>dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& values)
    {
        long long min_sum = 0;
        long long total_sum = values[node];

        for(const auto& next : adj[node])
        {
            if(next != parent)
            {
                auto p = dfs(next, node, adj, values);
                min_sum += p.first;
                total_sum += p.second;
            }
        }

        if(min_sum == 0) // leaf
        {
            min_sum = values[node];
        }else{
            min_sum = min<long long>(min_sum, values[node]);
        }

        return {min_sum, total_sum};
    }
};