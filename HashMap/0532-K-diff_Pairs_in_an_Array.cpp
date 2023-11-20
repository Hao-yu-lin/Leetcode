/*
題目：
https://leetcode.com/problems/k-diff-pairs-in-an-array/

解說：
使用 hash map 快速查找 ｋ diff 的值

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int, int> ump;
        for(const int& i : nums)
        {
            ump[i] ++;
        }

        int ans = 0;
        if(k == 0)
        {
            for(const auto& p : ump)
            {
                if(p.second > 1) ans++;
            }
            
        }else
        {
            for(const auto& p : ump)
            {
                if(ump.count(p.first - k)) ans++;
            }
        }

        return ans;
    }
};