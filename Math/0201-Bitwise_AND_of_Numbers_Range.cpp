/*
題目：
https://leetcode.com/problems/bitwise-and-of-numbers-range/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int offset = 0;

        while(left != right){
            left >>= 1;
            right >>= 1;
            offset ++;
        }

        return left << offset;
    }
};

