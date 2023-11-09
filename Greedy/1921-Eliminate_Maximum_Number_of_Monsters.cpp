/*
題目：
https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

解說：
先計算出每一個 Monsters 需要花多久時間才會到達 city，因為每一單位時間只能消滅一隻 Monsters。
因此從最快到達的開始消滅。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        const int n = dist.size();
        vector<int> times(n);
        for(int i = 0; i < n; i++)
        {
            if(dist[i]%speed[i])
                times[i] = dist[i]/speed[i]+1;
            else
                times[i] = dist[i]/speed[i];
        }

        sort(times.begin(), times.end());
        for(int i = 0; i < n; i++)
        {
            if(times[i] < (i+1)) return i;
        }

        return n;
    }
};