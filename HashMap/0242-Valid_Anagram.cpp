/*
題目：
https://leetcode.com/problems/valid-anagram/

解說：
使用一個陣列紀錄 26個英文字母出現次數。
s 中的字母進行 ++
t 中的字母進行 --

最後陣列中是否 26 個字母皆為 0

有使用到的觀念：
Hash Map
*/

#include "../code_function.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        size_t s_sz = s.length();
        size_t t_sz = t.length();
        if(s_sz != t_sz) return false;

        vector<int> count(26, 0);
        for(int i = 0; i < s_sz; ++i){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(const int& c : count){
            if(c != 0) return false;
        }
        return true;
    }
};