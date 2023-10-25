/*
題目：
https://leetcode.com/problems/word-break/

解說：
使用 recursion 的概念，若已經在 Dict 內則不用求解。
wordBreak("leetcode") = 
    wordBreak("") && inDict("leetcode")
||  wordBreak("l") && inDict("eetcode")
||  wordBreak("le") && inDict("etcode")
||  wordBreak("lee") && inDict("tcode")
||  wordBreak("leet") && inDict("code")
||  wordBreak("leetc") && inDict("ode")
||  wordBreak("leetco") && inDict("de")
||  wordBreak("leetcod") && inDict("e")




有使用到的觀念：
DP, Recursion
*/

#include "../code_function.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }

    bool wordBreak(const string& s, const unordered_set<string>& dict){
        if(dp.count(s)) return dp[s];
        if(dict.count(s)) return dp[s] = true;

        for(int j = 1; j < s.length(); j++){
            string left = s.substr(0, j);
            string right = s.substr(j);

            if(dict.count(right) && wordBreak(left, dict))
                return dp[s] = true;
        }
        return dp[s] = false;
    }
private:
    unordered_map<string, bool> dp;
};