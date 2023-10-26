/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

解說：
考慮兩種情況，有股票與沒有股票
今天沒有股票 = max(前一天沒股票, 前一天有股票+賣出獲利)
今天有股票 = max(前一天有股票, 前一天沒股票-今天買入)

有使用到的觀念：
DP, Greedy
*/

#include "../code_function.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n = prices.size();
        if(n < 2) return 0;

        int noShare = 0, withShare = -prices[0];

        for(int i = 1; i < n; i++)
        {
            noShare = max(noShare, withShare + prices[i]);
            withShare = max(withShare, noShare - prices[i]);
        }

        return noShare;
    }
};