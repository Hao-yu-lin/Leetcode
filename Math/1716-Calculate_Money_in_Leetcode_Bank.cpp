/*
題目：
https://leetcode.com/problems/calculate-money-in-leetcode-bank/

解說：

week 1 : [1, 2, 3, 4, 5, 6, 7] -> 28
week 2 : [2, 3, 4, 5 ,6, 7, 8] -> 28 + 7
week 3 : [3, 4, 5, 6, 7, 8, 9] -> 28 + 7 + 7

total = ( 28*w ) + ( 0 + 7 + 14 + .... + 7w)
      = 28*w + 7*w*(w-1)/2

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int totalMoney(int n) 
    {
        int week_cnt = n/7;
        int remain_days = n%7;

        int total = ((week_cnt * (week_cnt - 1))/2) * 7;
        total += week_cnt * 28;
        int remain = ((1+remain_days)*remain_days)/2 + week_cnt * remain_days;

        total += remain;
        return total;
    }
};
