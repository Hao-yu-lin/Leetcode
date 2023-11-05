/*
題目：
https://leetcode.com/problems/median-of-two-sorted-arrays/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total;

        for(auto &c : nums1){
            total.push_back(c);
        }
        for(auto &c : nums2){
            total.push_back(c);
        }

        sort(total.begin(), total.end());
        int n = total.size();

        if(n % 2 == 0){
            return ((double)(total[n/2] + total[n/2 - 1])/2);
        }else{
            return (double)total[n/2];
        }        
    }
};