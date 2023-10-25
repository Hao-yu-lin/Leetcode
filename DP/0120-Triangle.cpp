/*
題目：
https://leetcode.com/problems/triangle/

解說：
使用一個 DP 紀錄前一列的合，針對下一列的合，進行一個一個相加，取最小值
需特別注意兩邊的邊界要額外處理

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        const int n = triangle.size();
        if(n == 1) return triangle[0][0];

        vector<int>sum;
        sum.push_back(triangle[0][0]);

        for(int i = 1; i < n; i++)
        {
            vector<int>row_sum;
            for(int j = 0; j < i+1; j++)
            {
                int total;
                if(j == 0) total = sum[0] + triangle[i][0];
                else if(j == i) total = sum[i-1] + triangle[i][i];
                else total = min(sum[j-1], sum[j]) + triangle[i][j];
                row_sum.push_back(total);
            }
            sum = row_sum;
        }
        int ans = INT_MAX/2;
        for(const int c : sum)
        {
            ans = min(c, ans);
        }

        return ans;
    }
};