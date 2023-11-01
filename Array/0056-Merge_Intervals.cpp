/*
題目：
https://leetcode.com/problems/merge-intervals/

解說：
先將 intervals 進行 sorting 後進行比較
此時 intervals 會有幾個 case

Input [1, 3], [1, 6], [2, 7], [4, 5], [8, 9]

case 1. {[1, 3], [1, 6]} -> {[1, 6]}


case 2. {[1, 6]} + {[2, 7]} -> {[1, 7]}
因為 6 > 2 ，代表 [2, 7] 有左半部相交
因此比較[1, 6]與[2, 7] 尾巴誰比較大，較大者則為新的尾巴 [1, 7]

case 3. {[1, 7]} + [4, 5] -> {[1, 7]}
這是中間部份重疊，此時就不進行處理

case 4. {[1, 7]} + [8, 9] -> {[1, 7], [8, 9]}
當答案中最後一個數，大於目前比較的頭，7 < 8 時，代表這兩個區間沒有相交，因此直接放入 ans 中

有使用到的觀念：
sorting
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(const auto& v : intervals)
        {
            if(ans.empty() || v[0] > ans.back()[1]) ans.push_back(v);
            else
            {
                ans.back()[1] = max(v[1], ans.back()[1]);
            }
        }

        return ans;
    }
};