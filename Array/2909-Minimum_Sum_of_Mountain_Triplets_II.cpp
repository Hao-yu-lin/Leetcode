/*
題目：
https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/

解說：
兩個陣列，一個儲存該點往左的最小值，一個儲存該點往右的最小值
之後判斷 nums[i] > left_min[i] && nums[i] > right_min[i]，若成立計算 sum

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int min_sum = INT_MAX;
        
        const int n = nums.size();
        vector<int> left_min(n);
        vector<int> right_min(n);
        left_min[0] = nums[0];
        right_min[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++)
        {
            left_min[i] = min(left_min[i-1], nums[i]);
            right_min[n-i-1] = min(right_min[n-i], nums[n-i-1]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > left_min[i] && nums[i] > right_min[i]){
                min_sum = min(min_sum, nums[i] + left_min[i] + right_min[i]);
            }
            // cout << right_min[i];
        }
        // cout << endl;
        
        if(min_sum == INT_MAX) return -1;
        else return min_sum;
    }
};