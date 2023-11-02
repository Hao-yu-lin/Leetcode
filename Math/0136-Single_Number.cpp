/*
題目：
https://leetcode.com/problems/single-number
解說：
A xor A = 0
A xor 0 = A

有使用到的觀念：
xor
*/

#include "../code_function.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto &c : nums){
            ans ^= c;
        }

        return ans;
    }
};
