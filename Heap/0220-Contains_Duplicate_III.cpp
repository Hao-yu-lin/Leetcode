/*
題目：
https://leetcode.com/problems/contains-duplicate-iii/

解說：
本題使用 multiset 儲存 nums[i] 裡面的數字


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) 
    {
        multiset<long>ms;

        for(int j = 0; j < nums.size(); j++)
        {
            // 如果 j > indexDiff 代表超過 indexDiff 需要刪除前面的
            if(j>indexDiff) ms.erase(ms.lower_bound(nums[j-indexDiff-1])); 

            // nums[j]- valueDiff <= nums[i] <= nums[j] + valueDiff
            auto pos = ms.lower_bound((long)nums[j]-(long)valueDiff);

            if(pos != ms.end() && *pos-nums[j] <= valueDiff) return true;

            ms.insert(nums[j]);
        }

        return false; 
    }
};