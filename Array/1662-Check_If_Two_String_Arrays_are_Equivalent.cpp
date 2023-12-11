/*
題目：
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

解說：
使用兩個字串存 word1 與 word2 內的字，最後比對兩者是否相等

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        string b = "";

        for(auto& s : word1)
        {
            a += s;
        }

        for(auto& s : word2)
        {
            b += s;
        }

        return a==b;
    }
};