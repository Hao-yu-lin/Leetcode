/*
題目：
https://leetcode.com/problems/rotate-image

解說：
先從斜對角交換 再垂直中線交換

1 2 3        1 4 7        7 4 1
4 5 6  --->  2 4 8  --->  8 4 2
7 8 9        3 6 9        9 6 3

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        const int n = matrix.size();
        if(n == 1) return;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)\
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        for(int i = 0; i < n ; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
    }
};