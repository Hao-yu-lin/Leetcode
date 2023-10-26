/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

解說：
一個 ptr 紀錄目前擺放正確的位置，比較 ptr-1 與 ptr-2 值是否相同，若相同則跳過，往下一個位置看

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        const int n = nums.size();
        if(n <= 2 ) return n;

        int curr = 2;
        for(int i = 2; i < n; i++)
        {
            if(nums[i] == nums[curr-1] && nums[i] == nums[curr-2]) continue;
            nums[curr] = nums[i];
            curr++;
        }

        return curr;
    }
};