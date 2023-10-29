/*
題目：
https://leetcode.com/problems/roman-to-integer/

解說：
羅馬數字
I       VI
II      VII 
III     VIII
IV      IX  -> 可以從此處看出，當小的 symbol 出現在大的 Symbol 前面時，代表此處的 I 是作為 - 的存在
V       X

有使用到的觀念：
Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> ump;
        ump['I'] = 1;
        ump['V'] = 5;
        ump['X'] = 10;
        ump['L'] = 50;
        ump['C'] = 100;
        ump['D'] = 500;
        ump['M'] = 1000;

        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(ump[s[i]] < ump[s[i+1]])
            {
                ans -= ump[s[i]];
            }else
            {
                ans += ump[s[i]];
            }
        }

        return ans;
    }
};