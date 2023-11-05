/*
題目：
https://leetcode.com/problems/find-peak-element/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = left + (right - left)/2;

            if(mid == 0){
                if(nums[0] > nums[1])return mid;
                else left = mid + 1;
            }else if(mid == n-1){
                if(nums[n-1] < nums[n-2]) return mid;
                else right = mid - 1;
            }else if(nums[mid] > nums[mid+1] &&nums[mid] > nums[mid-1]){
                return mid;
            }else if(nums[mid] > nums[mid + 1]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return left;
    }
};