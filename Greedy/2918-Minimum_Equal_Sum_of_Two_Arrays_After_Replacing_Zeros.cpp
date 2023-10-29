/*
題目：
https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/

解說：
計算出 nums1, nums2 的 0 個數與總和

如果 count_1 == 0 想要有解時，必須 nums_1 > nums_2 + count_2 否則一定無解 -1
如果 count_2 == 0 想要有解時，必須 nums_2 > nums_1 + count_1 否則一定無解 -1
因此若 count_1 != 0 && count_2 != 0 則找 max(nums_2 + count_2,  nums_1 + count_1)

有使用到的觀念：
Greedy
*/

#include "../code_function.h"

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        int count_1 = 0;
        int count_2 = 0;
        
        long long sum_1 = 0;
        long long sum_2 = 0;
        
        for(const auto& n : nums1)
        {
            sum_1 += n;
            count_1 += (n == 0);
        }
        
        for(const auto& n : nums2)
        {
            sum_2 += n;
            count_2 += (n == 0);
        }
        
        if(count_1 == 0 && sum_1 < sum_2 + count_2) return -1;
        if(count_2 == 0 && sum_2 < sum_1 + count_1) return -1;
 
        return max(sum_1 + count_1, sum_2 + count_2);
        
    }
};