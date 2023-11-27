/*
題目：
https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

解說：
因為排序

ans[0] = sum( |ans[j] - nums[0]| )  0 < j < n
ans[1] = sum( |ans[j] - nums[1]| ) 
       = sum( |ans[j] - (nums[1] - nums[0] + nums[0])| )
       = sum( |ans[j] - nums[0]| ) + (|nums[1] - nums[0] | * n)
...
ans[i] = ans[i-1] + (nums[i] - nums[i-1]) * i - (nums[i]- nums[i-1]) * (n-i)

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        const int n = nums.size();

        vector<int> ans(n);
        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i] - nums[0];

        ans[0] = sum;
        for(int i = 1; i < n; i++)
        {
            ans[i] = ans[i-1] + (nums[i] - nums[i-1]) * i - (nums[i]- nums[i-1]) * (n-i);
        }   

        return ans;
    }
};