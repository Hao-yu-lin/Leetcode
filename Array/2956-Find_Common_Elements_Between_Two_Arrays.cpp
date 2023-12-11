/*
題目：
https://leetcode.com/problems/find-common-elements-between-two-arrays/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> cnt1(101, 0);
        vector<int> cnt2(101, 0);
        for(auto& n1 : nums1)
        {
            cnt1[n1]++;
        }
        
        for(auto& n2 : nums2)
        {
            cnt2[n2]++;
        }
        
        int ans1 = 0;
        for(auto& n1 : nums1)
        {
            if(cnt2[n1] != 0) ans1++;
        }
        
        int ans2 = 0;
        for(auto& n2 : nums2)
        {
            if(cnt1[n2] != 0) ans2++;
        }
        
        return {ans1, ans2};
    }
};