/*
題目：
https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

解說：
xor operation 有一個性質是 A^A^B = B，利用這性質即可得到解

有使用到的觀念：
xor
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        const int n = pref.size();
        vector<int> ans(n, 0);
        ans[0] = pref[0];
        for(int i = 1; i < n; i++)
        {
            ans[i] = pref[i-1]^pref[i];
        }
        return ans;
    }
};