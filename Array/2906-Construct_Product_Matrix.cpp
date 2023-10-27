/*
題目：
https://leetcode.com/problems/construct-product-matrix/

解說：
一個是由左往右乘的矩陣
一個是由右往左乘的矩陣
最後兩者相加

有使用到的觀念：
Array, Matrix
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int>(m, 1));
        vector<vector<int>> left(n, vector<int>(m, 1));
        vector<vector<int>> right(n, vector<int>(m, 1));

        constexpr int kMod = 12345;
        
        int tmp = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                left[i][j] = tmp;
                tmp *= (grid[i][j]% kMod);
                tmp = tmp % kMod;
            }
        }

        tmp = 1;
        for(int i = n-1; i >=0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                right[i][j] = tmp;
                tmp *= (grid[i][j]% kMod);
                tmp = tmp % kMod;
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            ans[i][j] = (left[i][j] * right[i][j])%kMod;
        }

        return ans;
            
    }
};