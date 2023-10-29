/*
題目：
https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

解說：
這是一個無限背包問題，在使用 cost 時必須從小到大，這樣字排序就會越來越大，假設有新的組合時，可以直接取代不用比較。

有使用到的觀念：
DP, Unbounded Knapsack
*/

#include "../code_function.h"

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) 
    {
        const int n = cost.size();
        vector<string>dp(target+1, "0");
        dp[0] = "";
        for(int i = 1; i <= target; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                int s = i - cost[j-1];
                if(s < 0 || dp[s] == "0" || dp[s].length() + 1 < dp[i].length()) continue;
                dp[i] = to_string(j) + dp[s];
            }
        }

        return dp[target];
    }
};