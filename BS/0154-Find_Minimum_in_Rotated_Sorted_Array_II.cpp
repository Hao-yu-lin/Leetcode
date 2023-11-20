/*
題目：
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

解說：

sol1
if (nums[left]<nums[mid] && nums[left]<nums[right])  // left,mid,right同在一个区间
    right=mid;  // 可以直接 return nums[left]
else if (nums[left]<nums[mid] && nums[left]>=nums[right]) // left,mid在左区间，right在右区间
    left=mid+1;
else if (nums[left]>=nums[mid] && nums[left]<nums[right]) // mid在右区间,right在左区间，不可能
    continue;
else if (nums[left]>=nums[mid] && nums[left]>=nums[right]) // left在左区间，mid,right在右区间
    right=mid;  
    
sol2
考虑到我们始终往右区间收敛，所以可以判定此时mid在右区间。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() -1;
        while(left < right)
        {
            while(left + 1 < right && nums[left] == nums[left+1])
                left++;
            int mid = left + (right - left)/2;

            if(left == right-1) return min(nums[left], nums[right]);

            if(nums[left] < nums[mid] && nums[left] >= nums[right])
                left = mid+1;
            else if(nums[left] < nums[mid] && nums[left] < nums[right])
                right = mid;
            else if(nums[left] >= nums[mid] && nums[left] < nums[right])
                continue;
            else if(nums[left] >= nums[mid] && nums[left] >= nums[right])
                right = mid;
        }

        return nums[left];
    }
};

class Solution2 {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0;
        int right = nums.size() -1;
        while(left < right)
        {
            int mid = left+(right-left)/2;  
            if (nums[mid] > nums[right])
                left = mid+1;
            else if (nums[mid] < nums[right])
                right = mid;
            else
                right -= 1;
        }

        return nums[left];
    }
};
