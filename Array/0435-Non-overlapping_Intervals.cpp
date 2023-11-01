/*
題目：


解說：
https://leetcode.com/problems/non-overlapping-intervals

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int count = 0;
        int i = 0;
        while(i < intervals.size())
        {
            count ++;
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] < intervals[i][1]) { 
                j++;
            }
            i = j;
        }

        return n-count;
    }
};