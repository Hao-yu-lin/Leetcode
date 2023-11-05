/*
題目：
https://leetcode.com/problems/search-a-2d-matrix/

解說：
關鍵在於 (i, j) = (mid/n, mid%n)

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int num = matrix[mid/n][mid%n];
            if(num == target) return true;
            else if(num > target) high = mid-1;
            else low = mid+1;
        } 

        return false;
    }
};