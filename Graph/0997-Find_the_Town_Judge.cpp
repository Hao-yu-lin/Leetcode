/*
題目：
https://leetcode.com/problems/find-the-town-judge/

解說：
[[1, 2]]  out 1 -> 2 in
只有一個 judge 因此該 judge 會被剩餘 n-1 指向，且 judge 不會往外指向

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);
        
        for(const auto& p : trust)
        {
            out[p[0]]++;
            in[p[1]]++;
        }

        for(int i = 1; i < n+1; i++)
        {
            if(in[i] == n-1 && out[i] == 0) return i;
        }

        return -1;

    }
};