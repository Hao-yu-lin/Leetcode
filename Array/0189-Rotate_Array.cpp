/*
題目：
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

解說：
使用一個暫存的陣列，存取位移後的值
之後將位移後的值，拷貝至原本的 nums 中

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        const int n = nums.size();

        vector<int> tmp(n, 0);
        for(int i = 0; i < n; i++)
        {
            tmp[(i+k)%n] = nums[i];
        }

        for(int i = 0; i < n; i++)
        {
            nums[i] = tmp[i];
        }
    }
};