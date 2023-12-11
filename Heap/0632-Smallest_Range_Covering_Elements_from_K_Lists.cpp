/*
題目：
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

解說：
使用一個 set，內存 nums 中每一個 group 的當前最小值，因此取 set 的最大最小值，即可形成涵蓋每一個 group 的 range
再每一次循環中，刪除當前的最小值，並加入該最小值所屬的 group 的下一個值
形成新的 set 再重新抓取 set 中的最大最小值，形成新的 range
反覆抓取，直到某一個 group 超出抓取的數值該 group 範圍

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        set<pair<int, int>> s;  //{val, groupID}
        const int n = nums.size();

        vector<int> pts;
        for(int i = 0; i < n; i++)
        {
            pts.push_back(0);
            s.insert({nums[i][0], i});
        }
        
        int range = INT_MAX;
        vector<int> ans;

        while(1)
        {
            int curr_max = s.rbegin()->first;
            int curr_min = s.begin()->first;

            if(curr_max - curr_min < range)
            {
                range = curr_max - curr_min;
                ans = {curr_min, curr_max};
            }

            int group = s.begin()->second;
            pts[group]++;
            if(pts[group] == nums[group].size()) break;
            s.erase(s.begin());
            s.insert({nums[group][pts[group]], group});
        }

        return ans;
    }
};