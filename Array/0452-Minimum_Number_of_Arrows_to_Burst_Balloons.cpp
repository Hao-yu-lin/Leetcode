/*
題目：


解說：
sort by start points：the minimum number of intervals to cover
sort by end points：the maximum number of non-overlapping intervals

透過尋找 non overlapping 個數，來知道至少要射幾顆氣球。


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        // ending points sorting
        sort(points.begin(), points.end(), cmp);

        int i = 0;
        int count = 0;
        while(i < points.size())
        {
            count ++;
            int j = i+1;
            while(j < points.size() && points[j][0] <= points[i][1]) j++;
            i = j;
        }
        return count;
    }
};