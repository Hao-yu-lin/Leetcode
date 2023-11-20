/*
題目：
https://leetcode.com/problems/sort-vowels-in-a-string/

解說：
使用一個 vector 進行 vowels 的儲存，並使用 '#' 做替換
之後將儲存的 vowels 進行 sorting 後，再重新將 '#' 按照 vowels 的順序進行替換

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char> vowel;

        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u' || s[i] == 'A' ||
                s[i] == 'E' || s[i] == 'I'|| s[i] == 'O' || s[i] == 'U')
                {
                    vowel.push_back(s[i]);
                    s[i] = '#';
                }
        }

        sort(vowel.begin(), vowel.end());
        int curr = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '#')
            {
                s[i] = vowel[curr];
                curr++;
            }
        }

        return s;
    }
};