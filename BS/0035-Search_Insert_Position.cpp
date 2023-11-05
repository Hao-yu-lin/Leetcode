/*
題目：
https://leetcode.com/problems/search-insert-position/

解說：


有使用到的觀念：
Binary Search
*/

#include "../code_function.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        const int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target)right = mid-1;
            else left = mid+1;
        }

        return left;
    }
};