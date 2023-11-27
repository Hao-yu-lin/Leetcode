/*
題目：
https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/

解說：
可以將 nums 看成 histogram，因此就是求一個 rectange，area > threshold
因此就轉換成與 0084 一模一樣的題目

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) 
    {
        nums.insert(nums.begin(), 0);
        nums.push_back(0);

        int n = nums.size();
        
        stack<int> stk;
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && nums[stk.top()] > nums[i])
            {
                int h = nums[stk.top()];
                stk.pop();
                int area = h * (i-stk.top()-1);
                if(area > threshold)
                    return i - stk.top()-1;
            }
            stk.push(i);
        }

        return -1;
    }
};