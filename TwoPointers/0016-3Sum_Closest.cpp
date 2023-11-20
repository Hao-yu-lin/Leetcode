/*
題目：
https://leetcode.com/problems/3sum-closest/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int small_diff = INT_MAX;
        int curr_small;
        const int n = nums.size();
        for(int i = 0; i < n-2; i++)
        {
            int left = i+1;
            int right = n-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(target - sum);
                if(small_diff > diff)
                {
                    small_diff = diff;
                    curr_small = sum;
                }
                if(sum == target) return target;
                else if(sum > target) right--;
                else left ++;
            }
        }

        return curr_small;
    }
};