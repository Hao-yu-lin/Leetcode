/*
題目：
https://leetcode.com/problems/power-of-two/

解說：
檢查為正值
n & (n-1) == 0 用於確認是否為 2 的倍數

有使用到的觀念：
Math, Bit Manipulation
*/
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n > 0 && (n&(n-1))==0;
    }
};