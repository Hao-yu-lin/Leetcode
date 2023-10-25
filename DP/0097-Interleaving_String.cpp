/*
題目：
https://leetcode.com/problems/interleaving-string/

解說：


有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        const int s1_len = s1.length();
        const int s2_len = s2.length();

        vector<vector<bool>> dp(s1_len+1, vector<bool>(s2_len+1, false));
        if(s1_len + s2_len != s3.length()) return false;

        dp[s1_len][s2_len] = true;

        for(int i = s1_len; i >= 0; i--){
            for(int j = s2_len; j >= 0; j--){
                if(i < s1_len && s1[i] == s3[i+j] && dp[i+1][j] == true) dp[i][j] = true;
                if(j < s2_len && s2[j] == s3[i+j] && dp[i][j+1] == true) dp[i][j] = true;
            }
        }
        return dp[0][0];
    }
};