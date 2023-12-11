/*
題目：
https://leetcode.com/problems/minimum-time-visiting-all-points/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int ans = 0;

        for(int i = 0; i < points.size()-1; i++)
        {
            int x_diff = abs(points[i][0] - points[i+1][0]);
            int y_diff = abs(points[i][1] - points[i+1][1]);
            ans += max(x_diff, y_diff);
        }

        return ans;
    }
};