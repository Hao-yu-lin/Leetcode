/*
題目：
https://leetcode.com/problems/palindrome-partitioning/

解說：
DP[i][j]: if true means that s[i:j] is palindrome
紀錄完後，使用 DFS 進行每一種可能性的組合

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    bool dp[16][16];
    vector<vector<string>> ans;
    int n;
public:
    vector<vector<string>> partition(string s) 
    {
        n = s.size();

        for(int i = 0; i < n; i++)
            dp[i][i] = true;
        for(int i = 0; i < n-1; i++)
            dp[i][i+1] = (s[i] == s[i+1]);

        for(int len = 3; len <= n; len++)
        {
            for(int i = 0; i+len-1 < n; i++)
            {
                int j = i+len-1;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = false;
            }
        }

        vector<string> tmp;
        dfs(0, tmp, s);

        return ans;
    }

    void dfs(int idx, vector<string>& tmp, string& s)
    {
        if(idx == n)
        {
            ans.push_back(tmp);
            return;
        }

        for(int j = idx; j < n; j++)
        {
            if(dp[idx][j])
            {
                tmp.push_back(s.substr(idx, j-idx+1));
                dfs(j+1, tmp, s);
                tmp.pop_back();
            }
        }
    }
};