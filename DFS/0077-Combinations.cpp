/*
題目：
https://leetcode.com/problems/combinations/

解說：
使用 DFS 來組合出每一種組合

有使用到的觀念：
DFS
*/

#include "../code_function.h"

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> tmp;
        dfs(n, k, 1, tmp);
        return ans;
    }

    void dfs(int n, int k, int curr, vector<int>& tmp)
    {
        
        if(tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }

        if(curr > n) return;

        for(int i = curr; i <= n; i++)
        {
            tmp.push_back(i);
            dfs(n, k, i+1, tmp);
            tmp.pop_back();
        }
    }
};
