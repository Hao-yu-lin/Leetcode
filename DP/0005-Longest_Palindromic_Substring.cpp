/*
題目：
https://leetcode.com/problems/longest-palindromic-substring/

解說：
針對 s 中的每一個字，以該字為中心向左向右擴散檢查。

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    string longestPalindrome(string s) 
    {
        const int n = s.length();
        int max_len = 0;
        int start = 0;

        for(int i = 0; i < n; i++)
        {
            int right = i;
            while(right < n && s[i] == s[right]) right++;

            int left = i-1;
            while(left >= 0 && right < n && s[left] == s[right]){
                left --;
                right ++;
            }

            int curr_len = right - left - 1;
            if(max_len < curr_len)
            {
                max_len = curr_len;
                start = left+1;
            }
        }

        return s.substr(start, max_len);
    }
};