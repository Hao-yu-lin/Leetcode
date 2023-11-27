/*
題目：
https://leetcode.com/problems/largest-submatrix-with-rearrangements/

解說：
使用一個 hist 累積 1 的數量，因為可以行交換，因此將 hist 遞減排序
透過下方方程式，取得目前的最小高度，最小高度 * j，則為該點的最大 matrix
for(int j = 0; j < n; j++)
{
    min_h = min(min_h, h[j]);
    ans = max(ans, (j+1)*min_h);
}

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        vector<int> hist(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 1)
                    hist[j] ++;
                else
                    hist[j] = 0;
            }

            auto h = hist;
            sort(h.begin(), h.end(), greater<int>());

            int min_h = INT_MAX;
            for(int j = 0; j < n; j++)
            {
                min_h = min(min_h, h[j]);
                ans = max(ans, (j+1)*min_h);
            }
        }
        return ans;
    }
};