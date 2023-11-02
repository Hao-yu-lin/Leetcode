/*
題目：
https://leetcode.com/problems/number-of-1-bits/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        int count = 0;
        while(n != 0)
        {
            count += n&1;
            n >>= 1;
        }
        return count;
    }
};