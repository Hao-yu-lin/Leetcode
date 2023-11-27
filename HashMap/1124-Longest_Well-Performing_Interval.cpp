/*
題目：
https://leetcode.com/problems/longest-well-performing-interval/description/

解說：
將 > 8 轉換成 += 1; < 8 -= 1，只要和 > 0 為 well perform
因此該題則轉換成 logest subarray sum with target
透過 hash table 方式紀錄，該和最早出現的時間點。

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        unordered_map<int, int> ump;
        int ans = 0;
        int s = 0;

        for(int i = 0; i < hours.size(); i++)
        {
            s += hours[i] > 8 ? 1 : -1;
            if(s > 0) ans = i+1;
            else
            {
                if(!ump.count(s)) ump[s] = i;
                if(ump.count(s-1))
                {
                    ans = max(ans, i-ump[s-1]);
                }
            }
        }

        return ans;
    }
};