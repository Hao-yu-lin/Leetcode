/*
題目：
https://leetcode.com/problems/array-partition/

解說：
因為題目去全部可能的 n 組合中，每一個 pair 的最小值相加後，求最大值
先將 nums 排序後，累加偶數位置的值即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i = i + 2)
        {
            ans += nums[i];
        }

        return ans;
    }
};