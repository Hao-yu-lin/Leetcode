/*
題目：
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

解說：
sol2 題目要找最小值，因此目標是右區間的第一個數，為最小值
如果中位數 nums[mid] > nums[right] 說明 mid 在左區間，將 left 設定為 mid + 1，將搜索範圍往右調整
若 nums[mid] < nums[right] 則說明 mid 在右區間，將 right 設定為 mid

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()- 1);
    }

private:
    int findMin(vector<int> &nums, int l, int r){
        if(l+1 >= r) return min(nums[l], nums[r]);

        if(nums[l] < nums[r] ) return nums[l];

        int mid = l + (r-l)/2;
        
        return min(findMin(nums, l, mid-1), findMin(nums, mid, r));
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
        }

        return nums[left];
        
    }
};