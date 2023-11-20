/*
題目：
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/

解說：
很難的題目
https://www.youtube.com/live/RZVPX3elY9I?si=dgZQb2HLom0NfPoJ

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) 
    {
        const int m = matrix.size();
        if(m == 0) return 0;
        const int n = matrix[0].size();

        if(m > n)
        {
            vector<vector<int>> matrix2(n, vector<int>(m, 0));
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    matrix2[j][i] = matrix[i][j];
            return maxSumSubmatrix(matrix2, K);
        }

        int result = INT_MIN;

        for(int i = 0; i < m; i++)
        {
            vector<int> row(n, 0);
            for(int j = i; j < m; j++)
            {
                for(int k = 0; k < n; k++)
                    row[k] += matrix[j][k];
                result = max(result, helper(row, K));
            }
        }

        return result;
        
    }

    int helper(vector<int>& row, int K)
    {
        set<int>s({0});
        int presum = 0;
        int result = INT_MIN;

        for(int i = 0; i < row.size(); i++)
        {
            presum += row[i];
            auto iter = s.lower_bound(presum - K);
            if(iter != s.end())
                result = max(result, presum- *iter);
            s.insert(presum);
        }

        return result;
    }
};