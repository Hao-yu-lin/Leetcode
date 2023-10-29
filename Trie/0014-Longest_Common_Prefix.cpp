/*
題目：
https://leetcode.com/problems/longest-common-prefix/

解說：


有使用到的觀念：
Trie
*/

#include "../code_function.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        const int n = strs.size();

        int max_prefix = strs[0].length();

        for(int i = 1; i < n; i++)
        {
            int curr_len = 0;
            while(curr_len < strs[0].length() && strs[i][curr_len] == strs[0][curr_len]) curr_len ++;
            max_prefix = min(max_prefix, curr_len);
        }    

        return strs[0].substr(0, max_prefix);
    }
};