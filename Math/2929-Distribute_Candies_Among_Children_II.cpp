/*
題目：
https://leetcode.com/problems/distribute-candies-among-children-ii/

解說：
先找出第一個數的最大與最小值 firstMin、firstMax
從 firstMin 到 firstMax 開始假設第一個數
則第二個數可以分配的區間最小值為 max(0, n-i-limit) 到 min(limit, n-i)
因為 candidate 必須被分配完，因此前兩個數確定後，第三個數也跟著確定
因此每一輪可以分配的數量為 min(limit, n-i) - max(0, n-i-limit)

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    long long distributeCandies(int n, int limit) 
    {
        long long ans = 0;
        int firstMin = max(0, n - 2 * limit);
        int firstMax = min(limit, n);

        for(int i = firstMin; i <= firstMax; i++)
        {
            int secondMin = max(0, n-i-limit);
            int secondMax = min(limit, n-i);
            ans += secondMax - secondMin + 1;
        }

        return ans;
    }
};