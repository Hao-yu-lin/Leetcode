/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

解說：
一個紀錄當前最大獲利，另一個紀錄當前最小值

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n = prices.size();
        int ans = 0;
        int curr_min = prices[0];

        for(int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - curr_min);
            curr_min = min(curr_min, prices[i]);
        }

        return ans;
    }
};