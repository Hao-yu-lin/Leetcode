/*
題目：
https://leetcode.com/problems/ransom-note/

解說：
使用 unordered_map 紀錄 magazine 中每一個 char 出現的次數。
然後再一一比對 ransomNote 內的字。

有使用到的觀念：
Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char, int> ump;

        for(const char& c : magazine)
        {
            ump[c] ++;
        }

        for(const char& c : ransomNote)
        {
            if(ump.find(c) != ump.end()){
                if(ump[c] == 0) return false;
                else ump[c]--;
            }else
                return false;
            
        }
        return true;
    }
};