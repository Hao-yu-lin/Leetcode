/*
題目：
https://www.hackerrank.com/challenges/bfsshortreach/problem

解說：


有使用到的觀念：

*/

#include "../code_function.h"

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<int> ans(n+1, -1);
    unordered_map<int, vector<int>>edge;
    for(const auto& p : edges)
    {
        edge[p[0]].push_back(p[1]);
        edge[p[1]].push_back(p[0]);
    }
    
    queue<int> q;
    for(const auto& next : edge[s])
    {
        q.push(next);
    }
    int curr = 0;
    while(!q.empty())
    {
        int size = q.size();
        curr++;
        while(size--)
        {
            int e = q.front();
            q.pop();
            if(ans[e] != -1) continue;
            ans[e] = curr * 6;
            for(const auto& next : edge[e]){
                q.push(next);
            }
        }
    }
    vector<int> final;
    for(int i = 1; i <= n; i++)
    {
        if(i == s) continue;
        else final.push_back(ans[i]);
    }
    return final;
}