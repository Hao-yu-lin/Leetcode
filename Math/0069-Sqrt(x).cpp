/*
題目：
https://leetcode.com/problems/sqrtx/

解說：
使用二分法的方式找平方根

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int mySqrt(int x) 
    {
        if(x < 2) return  x;
        int left = 0, right = x;

        long long mid;

        while(left < right)
        {
            mid = left + (right-left)/2;

            if(mid * mid <= x && (mid+1)*(mid+1) > x) return mid;
            else if(mid*mid < x) left = mid + 1;
            else right = mid;
        }

        return left - 1;
    }
};