/*
題目：
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

解說：
使用 hash map 紀錄出現的次數，確保出現次數皆低於 k，
透過 sliding windows 概念，若出現次數皆低於 k 則持續向右擴張，若高於 k 則左邊線向右內縮

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        unordered_map<int, int> ump;
        int left = 0;
        int right = 0;
        int n = nums.size();

        int ans = 0;
        while(right < n)
        {
            ump[nums[right]]++;
            while(ump[nums[right]] > k)
            {
                ump[nums[left]]--;
                left++;
            }
            ans = max(ans, (right-left)+1);
            right++;
        }
        return ans;
    }
};