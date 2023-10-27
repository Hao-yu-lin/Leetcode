/*
題目：
https://leetcode.com/problems/product-of-array-except-self/

解說：
建立兩個陣列，一個是左邊乘積，一個是右邊乘積，最後再兩者相乘

有使用到的觀念：
Array, Prefix Sum
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);

        for(int i = 1; i < n; i++)
        {
            left[i] = left[i-1] * nums[i-1];
            right[n-i-1] = right[n-i] * nums[n-i];
        }

        for(int i = 0; i < n; i++)
        {
            left[i] = left[i] * right[i];
        }
        return left;
    }
};