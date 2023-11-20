/*
題目：
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

解說：
因為要最小的 pair ，因此將 nums 排序後，最小的與最大相加，即可得到最小 pair

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int curr_max = INT_MIN;
        const int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left < right)
        {
            int sum = nums[left] + nums[right];
            curr_max = max(curr_max, sum);
            left ++;
            right --;
        }
        
        return curr_max;
    }
};