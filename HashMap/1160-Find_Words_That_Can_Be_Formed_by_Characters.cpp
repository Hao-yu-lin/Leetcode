/*
題目：
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        vector<int> cnt(26, 0);
        for(auto &c : chars)
        {
            cnt[c-'a'] ++;
        }

        int ans = 0;

        for(auto &s : words)
        {
            if(check(s, cnt))
            {
                ans += s.length();
            }
        }

        return ans;
    }

    bool check(string& word, vector<int>& cnt)
    {
        vector<int> word_cnt(26, 0);

        for(const char &c : word)
        {
            word_cnt[c-'a']++;
            if(word_cnt[c-'a'] > cnt[c-'a'])
            {
                return false;
            }
        }

        return true;
    }
};