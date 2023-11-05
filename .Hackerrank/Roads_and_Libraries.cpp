/*
題目：
https://www.hackerrank.com/challenges/torque-and-development/problem

解說：
計算 lib 與 city 建造成本，隨機選一個點進行 dfs，需用一個 vector 紀錄已經可以到達 lib，避免重複建造

有使用到的觀念：

*/

#include "../code_function.h"

int dfs(int i, unordered_map<int, vector<int>>&ump, vector<int>& visited)
{
    if(visited[i] == 1) return 0;
    int add = 0;
    visited[i] = 1;
    if(ump.find(i) != ump.end())
    {
        for(const int& nei : ump[i]){
            add += dfs(nei, ump, visited);
        }
    }
    return add+1;
}


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) 
{
    if(c_lib <= c_road) return (long)n * c_lib;
    
    unordered_map<int, vector<int>>ump;

    
    for(const auto& p : cities)
    {
        ump[p[0]].push_back(p[1]);
        ump[p[1]].push_back(p[0]);
    }
    
    long ans = 0;
    vector<int> visited(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == 0)
        {
            int add = dfs(i, ump, visited);
            
            ans += c_lib;
            ans += (long)(c_road * (add-1));
        }
    }
    
    return ans;
}