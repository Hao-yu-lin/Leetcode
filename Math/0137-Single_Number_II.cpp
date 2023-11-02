/*
題目：
https://leetcode.com/problems/single-number-ii/

解說：
因為每個數字重複三次，所以將數字使用二進制表示後，對每一位數加總起來 mod 3，可以得到剩餘的那個數字的 bits值

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        vector<int> bits(32, 0);
        for(int x : nums)
        {
            for(int i = 0; i < 32; i++)
            {
                bits[i] += (x >> i)&1;
            }
        }
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            ans += (bits[i]%3) << i;
        }

        return ans;
    }
};