/*
題目：
https://leetcode.com/problems/transpose-matrix/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                ans[j][i] = matrix[i][j];
            }
        return ans;
    }
};

