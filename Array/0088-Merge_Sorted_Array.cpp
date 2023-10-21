/*
題目：
https://leetcode.com/problems/merge-sorted-array/

解說：
使用兩個指標比較 nums1 與 nums2 的值誰比較大，從 nums1 的 m+n-1 位置，開始降序填充

有使用到的觀念：
Array、TwoPointer、Sorting
*/
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
    {
        int ptr1 = m-1, ptr2 = n-1, curr = m+n-1;

        while(ptr1 >= 0 && ptr2 >= 0)
        {
            if(nums1[ptr1] > nums2[ptr2])
            {
                nums1[curr] = nums1[ptr1];
                ptr1--;
            }else
            {
                nums1[curr] = nums2[ptr2];
                ptr2--;
            }
            curr--;
        }

        while(ptr2 >= 0)
        {
            nums1[curr] = nums2[ptr2];
            ptr2--;
            curr--;
        }
    }
};
