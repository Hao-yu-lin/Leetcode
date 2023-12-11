/*
題目：
https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/

解說：
使用一個 vector 紀錄每一個沙發的位置，計算相鄰兩個元素之間的間隔即可
因題目要兩個沙發為一組，因此 i+=2

有使用到的觀念：

*/

#include "../code_function.h"

using LL = long long;
LL M = 1e9+7;

class Solution {
public:
    int numberOfWays(string corridor) 
    {
        const int n = corridor.size();

        vector<int> pos;
        for(int i = 0; i < n; i++)
        {
            if(corridor[i] == 'S')
                pos.push_back(i);
        }
        
        if(pos.size() == 0 || pos.size() %2 != 0) return 0;

        LL ret = 1;
        for(int i = 2; i+2 <= pos.size(); i+=2)
        {
            LL diff = pos[i] - pos[i-1];
            ret *= diff;
            ret %= M;
        }

        return ret;
    }
};

