/*
題目：
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

解說：
把 words 中的單詞加入 hash map 中，做為統計 words 出現次數。
開始擴展窗戶，何時停止擴展？
給予的 s 長度減 words 長度+1，因為如果窗戶長度比此大時，無法裝入 words 內的字。
使用另一個 hash map 紀錄 s 中，看過的字。比對該字的出現次數是否多餘 words 內的字數，如果多代表不是此 subarray。
需要重新尋找。

有使用到的觀念：
Sliding Windows, Hash Table, String
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        int s_len = s.length();
        int words_count = words.size();
        int words_len = words[0].length();

        if(s_len < words_count * words_len || s_len == 0 || words_len == 0 || words_count == 0) return {};

        unordered_map<string, int> map1;
        for(const auto c : words)
        {
            map1[c]++;
        }

        vector<int> ans;
        int end = s_len - words_len * words_count + 1;
        for(int i = 0; i < end; ++i)
        {
            unordered_map<string, int> map2;
            for(int j = 0; j < words_count; j++)
            {
                int wordpos = i + j * words_len;
                string word = s.substr(wordpos, words_len);
                map2[word]++;

                if(map2[word] > map1[word]) break;
                if(j+1 == words_count) ans.push_back(i);
            }
        }
        return ans;
    }
};