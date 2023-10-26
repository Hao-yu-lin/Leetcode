/*
題目：
https://leetcode.com/problems/majority-element/

解說：
O(nlogn) 的寫法是，將 nums 進行排序後，取第 n/2 個位置的元素，為 majority element
O(n) 的做法，建立一個 hash map 作為計數器，並且當數值超過 n/2 + 1 時，該數為 majority element

有使用到的觀念：
Array, DP
*/

#include "../code_function.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> dp;
        const int n = nums.size();
        if(n == 1) return nums[0];
        for(int i = 0; i < n; i++)
        {
            dp[nums[i]] ++;
            
            if(dp[nums[i]] >= n/2+1) return nums[i];
            
        }

        return -1;
    }
};