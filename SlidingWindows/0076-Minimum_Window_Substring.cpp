/*
題目：
https://leetcode.com/problems/minimum-window-substring/

解說：
把 words 中的單詞加入 hash map 中，做為統計 words 出現次數。
使用三個參數， winStart 紀錄目前 subarray 的頭，matched 紀錄目前符合 t 的字數個數，subStart 紀錄目前最小的字串起始位置。
對於 s 字串，從頭開始一一比對，若出現符合 t 的數字，則 hashmap 會記載，將 hash map 紀錄出現的次數 -1。
當 matched == t 的次數時，代表目前從 winstart -> end 內包含 t 全部的字，計算是否會最小的 length。
winstart 往右開始縮小，若是有 t 的字且 hash map中出現的次數已經 == 0 而非負值時，matched -- 並且 hash map 內的值 ++。
若 hash map 出現的次數是負值，代表可以繼續往右縮小，因為會有另一個重複的值，可以使得 windows 更小。

有使用到的觀念：
Sliding Windows, Hash Table, String
*/

#include "../code_function.h"

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int winStart = 0, matched = 0, subStart = 0;
        int m = s.length(), n = t.length();
        int minLen = m+1;
        unordered_map<char, int> ump;
        
        for(const char c : t)
        {
            ump[c]++;
        }

        for(int end = 0; end < m; end++)
        {
            char c = s[end];
            if(ump.find(c) != ump.end())
            {
                ump[c] --;
                if(ump[c] >= 0) matched++;
            }

            while(matched == n)
            {
                if(minLen > end - winStart + 1)
                {
                    minLen = end - winStart+1;
                    subStart = winStart;
                }
                char lc =  s[winStart];
                if(ump.find(lc) != ump.end())
                {
                    if(ump[lc] == 0) matched--;
                    ump[lc]++;
                }
                winStart++;
            }
        }
        if(minLen > m) return "";
        else return s.substr(subStart, minLen);
    }
};