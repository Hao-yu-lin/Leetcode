/*
題目：
https://leetcode.com/problems/shifting-letters/

解說：
使用 由後往前 sum 的方式進行位移

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) 
    {
        const int n = s.length();
        

        long gain = 0;
        for(int i = n-1; i >= 0; i--)
        {
            gain = (gain + (shifts[i] % 26))%26;
            s[i] = 'a' + (s[i] - 'a' + gain) % 26;
        }  
        return s;
    }
};