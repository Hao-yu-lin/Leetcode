/*
題目：
https://leetcode.com/problems/search-in-rotated-sorted-array/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(target == nums[mid]) return mid;

            if(nums[left] <= target){
                if(nums[left] > nums[mid] || target < nums[mid]) right = mid-1;
                else
                    left = mid + 1;
            }else{
                if(nums[right] < nums[mid] || target > nums[mid]) left = mid + 1;
                else 
                    right = mid-1;
            }
        }

        return -1;     
    }
};
