/*
題目：
https://leetcode.com/problems/word-pattern/

解說：
與 0205 類似

有使用到的觀念：
Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> ump1;
        unordered_map<string, char> ump2;

        int n1 = pattern.length();
        int n2 = s.length();

        int curr_s = 0;
        for(int i = 0; i < n1; i++)
        {
            string tmp = "";
            if(curr_s > n2) return false;
            
            while(curr_s < n2 && s[curr_s] != ' ')
            {
                tmp += s[curr_s];
                curr_s ++;
            }
            curr_s++;
            if(ump1.count(pattern[i]) == 0 && ump2.count(tmp) == 0){
                ump1[pattern[i]] = tmp;
                ump2[tmp] = pattern[i];
            }else if(ump1.count(pattern[i]) == 1 && ump2.count(tmp) == 1){
                if(ump1[pattern[i]] == tmp && ump2[tmp] == pattern[i]) continue;
                else return false;
            }else{
                return false;
            }
        }
        if(curr_s < n2) return false;
        return true;
    }
};