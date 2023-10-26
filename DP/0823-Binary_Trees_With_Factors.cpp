/*
題目：
https://leetcode.com/problems/binary-trees-with-factors/

解說：
dp[i] = sum(dp[j] * dp[i/j]) , 0 <= j < i
arr[i] is a factor of arr[j] and arr[i]/arr[j] also in arr

有使用到的觀念：
DP, Hash Table
*/

#include "../code_function.h"

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        constexpr long kMod = 1000000007;
        const int n = arr.size();
        sort(arr.begin(), arr.end());
        
        unordered_map<int, long> dp;
        for(int i = 0; i < n; i++)
        {
            dp[arr[i]] = 1;
            for(int j = 0; j < i; j++)
            {
                if(arr[i]%arr[j] == 0 && dp.count(arr[i]/arr[j]))
                {
                    dp[arr[i]] += (dp[arr[i]/arr[j]] * dp[arr[j]])%kMod;
                }
            }
        }

        long ans = 0;
        for(const auto kv : dp)
        {
            ans += kv.second;
           
        }
        return ans%kMod;
    }
};