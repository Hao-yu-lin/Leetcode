/*
題目：
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        const int n = needle.length();
        const int h = haystack.length();

        if(n > h) return -1;

        for(int i = 0; i < h - n + 1; i++)
        {
            string tmp = haystack.substr(i, n);
            if(tmp == needle) return i;
        }
        return -1;
    }
};