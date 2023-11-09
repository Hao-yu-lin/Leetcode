/*
題目：
https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

解說：
只要有連接到，代表會有 indegree 因此只要計算誰的 indegree 是 0 即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n, 0);
        for(auto& e : edges)
        {
            indegree[e[1]]++;
        }

        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)  ans.push_back(i);
        }

        return ans;
    }
};