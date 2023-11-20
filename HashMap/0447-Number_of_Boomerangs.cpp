/*
題目：
https://leetcode.com/problems/number-of-boomerangs/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int result = 0;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<long, int>ump;

            for(int j = 0; j < points.size(); j++)
            {
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                long dist = x*x + y*y;
                ump[dist] ++;
            }

            for(auto a : ump)
            {
                result += a.second * (a.second-1);
            }
        }

        return result;
    }
};