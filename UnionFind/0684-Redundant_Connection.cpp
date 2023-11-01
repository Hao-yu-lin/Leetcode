/*
題目：
https://leetcode.com/problems/redundant-connection

解說：
使用 union find 方式將每一個邊給 union，如果發現到沒辦法 union 代表先前已經連再一起，因此就是答案

有使用到的觀念：
Union Find
*/

#include "../code_function.h"

class UnionFindSet{
    vector<int> parents_;
    vector<int> ranks_;
public:
    UnionFindSet(int n)
    {
        ranks_ = vector<int>(n+1, 0);
        parents_ = vector<int>(n+1, 0);

        for(int i = 0; i < parents_.size(); ++i)
            parents_[i] = i;
    }

    bool Union(int u, int v)
    {
        int p_u = Find(u);
        int p_v = Find(v);
        if(p_u == p_v) return false;

        if(ranks_[p_v] < ranks_[p_u]) parents_[p_v] = p_u;
        else if(ranks_[p_v] > ranks_[p_u]) parents_[p_u] = p_v;
        else{
            parents_[p_v] = p_u;
            ranks_[p_u] += 1;
        }

        return true;
    }

    int Find(int u)
    {
        if(u != parents_[u])
            parents_[u] = Find(parents_[u]);
        return parents_[u];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        UnionFindSet s(edges.size());
        for(const auto& edge : edges)
        {
            if(!s.Union(edge[0], edge[1])) return edge;
        }

        return {};
    }
};