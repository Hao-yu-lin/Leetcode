/*
題目：
https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

解說：
根據題意，要取得最大值的方法為，將數字排序後，由後挑選兩兩一組，紀錄較小的那一個

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int pair = n/3;

        int ans = 0;
        for(int i = 0; i < pair; i++)
        {
            ans += piles[n - 2*i - 2];
        }

        return ans;
    }
};