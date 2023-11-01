/*
題目：
https://leetcode.com/problems/set-matrix-zeroes/

解說：
使用兩個陣列一個是 row/col 紀錄哪些 row/col 須為 0
瀏覽每一個點，若為 0 則紀錄該 row 與 col
之後再重新瀏覽過，若該 row 或 col 被標記須為 0 則將他設定成 0

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                {
                    row[i] = true;
                    col[j] = true;
                }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(row[i] || col[j]) matrix[i][j] = 0;
    }
};