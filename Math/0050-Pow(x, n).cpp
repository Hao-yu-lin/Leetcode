/*
題目：
https://leetcode.com/problems/powx-n/

解說：
如果次方 == 0 return 1
如果次方 < 0 則將數字變成倒數後，再進行正的次方

次方拆分方式使用 x * myPow(x*x, n/2) 或 myPow(x*x, n/2);

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0) return 1;

        if( n < 0)
        {
            x = 1/x;
            n = abs(n);
        }

        if(n % 2 == 0) return myPow(x*x, n/2);
        else return x * myPow(x*x, n/2);
    }
};