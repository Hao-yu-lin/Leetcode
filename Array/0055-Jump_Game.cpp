/*
題目：
https://leetcode.com/problems/jump-game/

解說：
從後面開始檢查，last 代表保證可以跳到最後一位的值
如果 i 位置 + nums[i] > last 代表從 i 位置也可以跳到最後，last 會被更新成 i 

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int last = nums.size()-1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            if(nums[i] + i >= last) last = i;  
        }
        
        return last == 0;
    }
};