/*
題目：
https://leetcode.com/problems/interval-list-intersections/

解說：
因為兩個陣列已經排序。使用兩個 pointer 指向當前兩個序列的第一區間
如果這兩個區間不相交，將區間更早的那個序列指針 + 1
如果這兩個區間有相交，則放入相交的部分。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        vector<vector<int>> ans;

        int curr_1 = 0;
        int curr_2 = 0;

        int l1_len = firstList.size();
        int l2_len = secondList.size();

        while(curr_1 < l1_len && curr_2 < l2_len)
        {
            if(firstList[curr_1][1] < secondList[curr_2][0])
                curr_1 ++;
            else if(firstList[curr_1][0] > secondList[curr_2][1])
                curr_2 ++;
            else
            {
                int start = max(firstList[curr_1][0], secondList[curr_2][0]);
                int end = min(firstList[curr_1][1], secondList[curr_2][1]);
                ans.push_back({start, end});
                if(firstList[curr_1][1] < secondList[curr_2][1])
                    curr_1 ++;
                else
                    curr_2 ++;
            }
        }

        return ans;
    }
};