/*
題目：
https://leetcode.com/problems/contiguous-array/

解說：
建立 prefixsum ，遇到 1 -> prefixsum++ 遇到 0 -> prefixsum --
目標是 prefixsum = 0 則代表具有相同數目的 0 和 1

建立一個 ump 紀錄每個 prefixsum 的出現最早位置，求 i - ump[prefixsum]

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> ump;
        ump[0] = -1;
        int presum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1) presum += 1;
            else presum -= 1;

            if(ump.find(presum) != ump.end())
                ans = max(ans, i - ump[presum]);
            else
                ump[presum] = i;
        }

        return ans;
    }
};