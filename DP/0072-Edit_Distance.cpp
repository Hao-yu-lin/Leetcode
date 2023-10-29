/*
題目：
https://leetcode.com/problems/edit-distance/

解說：

d(i, j) 表示把 str1 前 i 个字符编辑成 str2 前 j 个字符所需要的最小 edit distance

        d(2, 1)     = 1 + d(1, 1)
edit("ab", "a")  = 1 + edit("a", "a")  <- delete "b" from str1

        d(1, 2)     = 1 + d(1, 1)
edit("a", "ab") = 1 + edit("a", "a")  <- insert "b" into str1

        d(2, 2)     = 1 + d(1, 1)
edit("ab", "ac") = 1 + edit("a", "a") <- replace "b" with "c" in str1

dp[i][j] = dp[i-1][j-1] if(word1[i] == word2[j])
           dp[i-1][j-1]+1  replace 把 i 位置的值 換成 j 位置的值
           dp[i][j-1]+1 insert
           dp[i-1][j]+1 delete



有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution1 {
public:
    int minDistance(string word1, string word2) 
    {
        int l1 = word1.length();
        int l2 = word2.length();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2+1, -1));
        return calDist(word1, word2, l1, l2, dp);
    }

    int calDist(const string& word1, const string& word2, int l1, int l2, vector<vector<int>>& dp)
    {
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;

        if(dp[l1][l2] >= 0) return dp[l1][l2];

        int ans;

        if(word1[l1-1] == word2[l2-1]) ans = calDist(word1, word2, l1-1, l2-1, dp);
        else ans = min(calDist(word1, word2, l1-1, l2-1, dp), // replace
                        min(calDist(word1, word2, l1-1, l2, dp),    // insert
                            calDist(word1, word2, l1, l2-1, dp) // replace
                            )
                        )+1;

        return dp[l1][l2] = ans;
    }
};

class Solution2 {
public:
    int minDistance(string word1, string word2) 
    {
        const int l1 = word1.size();
        const int l2 = word2.size();

        word1.insert(word1.begin(), '0');   
        word2.insert(word2.begin(), '0');   

        vector<vector<int>> dp(l1+1, vector<int>(l2+1, INT_MAX/2));

        dp[0][0] = 0;
        for(int i = 1; i <= l1; i++) dp[i][0] = i;
        for(int j = 1; j <= l2; j++) dp[0][j] = j;

        for(int i = 1; i <= l1; i++)
        {
            for(int j = 1; j <= l2; j++)
            {
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        return dp[l1][l2];
    }
};