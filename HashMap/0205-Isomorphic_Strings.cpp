/*
題目：
https://leetcode.com/problems/isomorphic-strings/

解說：
使用兩個 unordered_map 一個紀錄 s->t 的轉換，另一個紀錄 t->s 的轉換。

有使用到的觀念：
Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> ump1;
        unordered_map<char, char> ump2;

        int n = s.length();

        for(int i = 0; i < n; i++)
        {
            if(ump1.count(s[i]) == 0 && ump2.count(t[i]) == 0){
                ump1[s[i]] = t[i];
                ump2[t[i]] = s[i];
            }else if(ump1.count(s[i]) == 1 && ump2.count(t[i]) == 1){
                if(ump1[s[i]] == t[i] && ump2[t[i]] == s[i]) continue;
                else return false;
            }else{
                return false;
            }
        }

        return true;
    }
};