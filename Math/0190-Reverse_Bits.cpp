/*
題目：
https://leetcode.com/problems/reverse-bits/

解說：
Bit operation

Base-10 time case:
    ans = asn * 10 + n%10
    n/10


Base-2 
    ans = ans * 2 + n%2 -> n is positive
    n/2
or
    ans = (ans << 1) | (n&1)
    n >>= 1

But need to handle learding zeros
00110 -> 01100 not 011

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans = 0;
        for(int i = 0; i < 32; ++i){
            ans = (ans << 1) | (n&1);
            n >>= 1;
        }
        return ans;
    }
};

