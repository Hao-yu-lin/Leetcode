/*
題目：
https://leetcode.com/problems/decode-ways/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    unordered_map<string, int> ump;
public:
    int numDecodings(string s) 
    {
        if(s.length() == 0) return 0;
        ump[""] = 1;

        return ways(s);
    }

    int ways(const string& s)
    {
        if(ump.count(s)) return ump[s];
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;

        int w = ways(s.substr(1));
        const int prefix = stoi(s.substr(0, 2));
        if(prefix <= 26)
            w += ways(s.substr(2));
        ump[s] = w;
        return w;
    }
};