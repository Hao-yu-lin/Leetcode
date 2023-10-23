/*
題目：
https://leetcode.com/problems/remove-element/

解說：
使用一個計數器 count ，紀錄現在的位置。
從 i = 0 開始檢查每一個數值，如果該數值不等於 val 時。
與 count 進行交換，即代表 count 之前都是不等於 val 的數值。

有使用到的觀念：
Array, TwoPointer
*/
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) 
    {
        int count = 0;
        const int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != val)
            {
                if(i != count) nums[count] = nums[i];
                count ++;
            }
        }
        return count;
    }
};