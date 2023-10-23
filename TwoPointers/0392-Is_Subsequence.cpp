/*
題目：
https://leetcode.com/problems/is-subsequence/

解說：
一個指標，指向目前 curr 檢查到的位置。
從頭開始檢查 t 的值，若是有與 s[curr] 相等的，就將 curr++。
如果 curr 到達 s 的尾巴 return true 否則 return false

有使用到的觀念：
Two Pointers, String
*/
#include <string>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) 
    {
        const int s_len = s.length();
        const int t_len = t.length();

        int curr = 0;
        for(int i = 0; i < t_len; i++)
        {
            if(curr == s_len) return true;
            if(s[curr] == t[i])curr++;
        }
        if(curr == s_len) return true;
        return false;
    }
};