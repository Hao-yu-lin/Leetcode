/*
題目：
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstpos = findpos(nums, target);
        int endpos = findpos(nums, target+1)-1;

        if(firstpos <= endpos) return {firstpos, endpos};
        else return {-1, -1};
    }

    int findpos(vector<int>& nums, int target){
        int firstpos = nums.size();
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                firstpos = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return firstpos;
    }
};