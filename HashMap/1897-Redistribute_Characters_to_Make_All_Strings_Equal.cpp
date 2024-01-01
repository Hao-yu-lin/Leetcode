/*
題目：
https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool makeEqual(vector<string>& words) 
    {
        int n = words.size();
        vector<int> cnt(26, 0);
        for(auto &w : words)
            for(auto &c : w)
                cnt[c-'a']++;

        for(int i = 0; i < 26; i++)
            if(cnt[i]%n != 0) return false;
        return true;    
    }
};