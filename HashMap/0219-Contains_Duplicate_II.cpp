/*
題目：
https://leetcode.com/problems/contains-duplicate-ii

解說：
將出現過的數字，放入 ump 中{數字, 位置}
若重複出現，則比較現在的位置與 ump 內存的位置差距是否 <= k

有使用到的觀念：
Hash Map
*/

#include "../code_function.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int, int> ump;
        for(int i = 0; i < nums.size(); i++)
        {
            if(ump.find(nums[i]) != ump.end())
            {
                if(i-ump[nums[i]] <= k) return true;
            }

            ump[nums[i]] = i;

        }    
        return false;
    }
};