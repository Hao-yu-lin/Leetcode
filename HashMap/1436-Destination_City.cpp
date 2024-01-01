/*
題目：
https://leetcode.com/problems/destination-city/

解說：
destination city 是沒有任何 outgoing path，因此只要計算 outgoing 數量有多少
最後檢查沒有 outgoing 的即可

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string, int>ump;
        
        for(auto it : paths)
        {
            ump[it[0]]++;
        }

        for(auto it : paths)
        {
            if(ump[it[1]] < 1) return it[1];
        }
        return "";
    }
};