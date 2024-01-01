/*
題目：
https://leetcode.com/problems/count-pairs-of-points-with-distance-k/

解說：
此題關鍵點為 k <= 100
因此遍歷每一種 k 的可能情形，而不是遍歷每一種 coordinates。
並且利用 x * 1000000 + y 來當作 code ，作為 hash map 的輸入

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) 
    {
        unordered_map<long long, int> ump;
        int ans = 0;
        
        for(int i = 0; i < coordinates.size(); i++)
        {
            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];

            for(int a = 0; a <= k; a++)
            {
                int x2 = a^x1;
                int y2 = (k-a)^y1;

                long long code = (long long)x2*1000000 + y2;
                if(ump.find(code) != ump.end())
                {
                    ans += ump[code];
                }
            }

            long long code2 = (long long)x1*1000000 + y1;
            ump[code2] ++;
        }

        return ans;
    }
};