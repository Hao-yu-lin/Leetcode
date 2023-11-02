/*
題目：
https://leetcode.com/problems/combination-sum/

解說：
使用 DFS 探求每一個可能，需注意的是
這邊 target 是使用 target - candidates[i]，又因為 candidates 都是正數，因此如果 target < 0 時需要直接 return
因為可以重複使用 candidates 因此在抓取 candidates 的起始位置可以與前一層一樣

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int n;
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> tmp;
        n = candidates.size();
        dfs(candidates, target, 0, tmp);
        return ans;
    }

    void dfs(vector<int>& candidates, int target, int curr, vector<int> tmp)
    {
        if(target < 0) return;
        else if(target == 0) 
        {
            ans.push_back(tmp);
            return;
        }

        for(int i = curr; i < n; i++)
        {
            tmp.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i, tmp);
            tmp.pop_back();
        }
        
    }
};