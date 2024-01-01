/*
題目：
https://leetcode.com/problems/find-the-longest-equal-subarray/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        unordered_map<int, vector<int>> ump;
        for(int i = 0;i < nums.size(); i++)
            ump[nums[i]].push_back(i);

        int ans = 0;
        for(auto &[key, pos] : ump)
        {
            int j = 0;
            for(int i = 0; i < pos.size(); i++)
            {
                while(j < pos.size() && (((pos[j]-pos[i]+1) - (j-i+1)) <= k))
                {
                    ans = max(ans, j-i+1);
                    j++;
                }
            }
        }

        return ans;
    }
};