/*
題目：
https://leetcode.com/problems/longest-consecutive-sequence/
解說：

solution 1
Hash Map: {key, len} 

case1：no neighbor
    ump[key] = 1;

case2：has a single neighbor, extend
    l = ump[key +/- 1]
    ump[key +/- 1] = ump[key] = l + 1
 
case3: has tow neighbors, a bridge
    l = ump[key - 1]
    r = ump[key + 1]
    len = l + r + 1
    h[key - l] = h[key + r] = len

Input: {1, 2, 3, 6, 5, 4}
put 1 => {1:1}
put 2 => {1:1} + {2:1} -> {1:2}{2:2}
put 3 => {1:2}{2:2} + {3:1} -> {1:3}{2:2}{3:3}  we don't care about {2:2}
put 6 => {1:3}{2:2}{3:3}, {6:1} current has two neighbors
put 5 => {1:3}{2:2}{3:3}, {6:1} + {5:1} -> {1:3}{2:2}{3:3}, {5:2}{6:2}
put 4 => {1:3}{2:2}{3:3}, {5:2}{6:2} + {4:1} -> {1:6}{2:2}{3:3}{4:1}{5:2}{6:6}

有使用到的觀念：
Hash Map
*/

#include "../code_function.h"

class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans = 0;
        unordered_map<int, int> ump;
        for(const int& w : nums)
        {
            if(ump.count(w)) continue;

            auto it_l = ump.find(w - 1);
            auto it_r = ump.find(w + 1);

            int l = it_l == ump.end() ? 0 : it_l->second;
            int r = it_r == ump.end() ? 0 : it_r->second;

            // if(l > 0 && r > 0)
            //     ump[w] = ump[w-l] = ump[w+r] = l+r+1;
            // else if(l > 0)
            //     ump[w] = ump[w-l] = l+1;
            // else if(r > 0)
            //     ump[w] = ump[w+r] = r+1;
            // else
            //     ump[w] = 1;

            int len = l + r + 1;
            ump[w] = ump[w-l] = ump[w+r] = len;

            ans = ans = max(ans, len);
        }

        return ans;
    }
};

