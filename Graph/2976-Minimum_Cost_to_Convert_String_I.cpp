/*
題目：


解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX/3)); // dp[orig][change] = cost

        for(int i = 0; i < original.size(); i++)
        {
            dp[original[i]-'a'][changed[i]-'a'] = min(dp[original[i]-'a'][changed[i]-'a'], (long long)cost[i]);
        }   
        
        for(int i = 0; i < 26; i++)
            dp[i][i] = 0;

        for(int k = 0; k < 26; k++)
            for(int i = 0; i < 26; i++)
                for(int j = 0; j < 26; j++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        
        long long ans = 0;
        for(int i = 0; i < source.length(); i++)
        {
            if(dp[source[i]-'a'][target[i]-'a'] >= LLONG_MAX/3) return -1;
            ans += dp[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};