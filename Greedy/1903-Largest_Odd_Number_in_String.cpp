/*
題目：
https://leetcode.com/problems/largest-odd-number-in-string/

解說：
從後往前找第一個奇數

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string largestOddNumber(string num) 
    {
        string ans = "";

        int pos = num.length()-1;
        for(;pos >= 0; pos--)
        {
            int w = num[pos]-'0';
            if(w%2 == 1)
            {
                break;
            }
        }
        if(pos >= 0)
          ans = num.substr(0, pos+1);

        return ans;
    }
};