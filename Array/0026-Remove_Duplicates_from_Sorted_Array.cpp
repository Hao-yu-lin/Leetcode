/*
題目：
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

解說：
使用一個計數器，紀錄最後不重複的 num 個數，同時代表即將被交換的位置
判斷方式就是，當前的 i 與計數器位置的前一個值是否相等，若相等代表出現過，則去看下一個數字。
若不相等檢查 i 與計數器的值是否一樣，若不一樣則交換

有使用到的觀念：
Array, Two Pointers
*/
#include "../code_function.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() == 1) return 1;
        int count = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != nums[count-1]
            ){
                if(i != count)
                {
                    nums[count] = nums[i];
                }
                count++;
            }
        }
        return count;
    }
};
