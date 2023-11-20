/*
題目：
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/

解說：
使用兩個陣列，存該點以左的字母個數，與該點以右字母個數，並使用一個 unordered_set 來儲存已經出現過的 palindromic

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int>left(26);
        vector<int>right(26);

        unordered_set<string> us;

        // right accumulate
        for(int i = 0; i < s.size(); i++)
        {
            right[s[i] - 'a']++;
        } 

        for(int i = 0; i < s.size(); i++)
        {
            right[s[i] - 'a']--;

            for(int j = 0; j < 26; j++)
            {
                if(left[j] > 0 && right[j] > 0)
                {
                    char x = 'a' + j;
                    string tmp = "";
                    tmp += x;
                    tmp += s[i];
                    tmp += x;

                    if(us.count(tmp) == true) continue;

                    us.insert(tmp);
                }
            }
            left[s[i] - 'a']++;
        }

        return us.size();
    }
};