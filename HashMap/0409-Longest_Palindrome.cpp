/*
題目：
https://leetcode.com/problems/longest-palindrome/

解說：
使用 hash map 紀錄 char 出現的次數，並且一個紀錄是否為 odd state

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> ump;
        bool odd_state = false;
       
        int len = 0;

        for(const auto& c : s)
        {
            ump[c] ++;
        }

        for(const auto& p : ump)
        {
            if(p.second%2 == 0)
            {
                len += p.second;
            }else
            {
                len += p.second-1;
                odd_state = true;
            }
        }

        if(odd_state) return len+1;
        return len;
    }
};