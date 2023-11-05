/*
題目：
https://www.hackerrank.com/challenges/journey-to-the-moon/problem

解說：
使用 Union Find 找出 group，然後利用 ump 紀錄不同國家的個數

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

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    UnionFindSet s(n);
    for(const auto& p : astronaut)
    {
        s.Union(p[0], p[1]);
    }
    
    unordered_map<int, int> ump;
    for(int i = 0; i < n; i++)
    {
        ump[s.Find(i)]++;
    }
    
    vector<int> result;
    long long sum = 0, result1 = 0;
    for(auto& p : ump)
    {
        result.push_back(p.second);
        sum += p.second;
    }
    
    for(int i = 0; i < result.size()-1; i++)
    {
        sum -= result[i];
        result1 += (result[i] * sum);
    }
    return result1;
}