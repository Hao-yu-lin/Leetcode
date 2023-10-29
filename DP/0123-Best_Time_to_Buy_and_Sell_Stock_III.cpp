/*
題目：
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

解說：
紀錄兩次的交易值，取最大
buy1:只有進行一次購買交易，所能得到的最大獲利
buy1 = max(buy1, -prices[i])

sell1:進行一次購買與賣出，所能獲得的最大獲利
sell1 = max(sell1, buy1+prices[i]) 再進行賣出前，必須有買入的情形，因此最大獲利來源為 買入後賣出 或 保持不動



有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        const int n = prices.size();
        if(n == 0) return 0;
        
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for(int i = 1; i < n; i++)
        {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }

        return max(sell1, sell2);
    }
};