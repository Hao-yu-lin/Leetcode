/*
題目：
https://leetcode.com/problems/factorial-trailing-zeroes/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        while(n >= 5){
            sum += (n/5);
            n /= 5;
        }
        return sum;
    }
};