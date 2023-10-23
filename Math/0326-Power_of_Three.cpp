/*
題目：
https://leetcode.com/problems/power-of-three/

解說：


有使用到的觀念：
Math, Recursion
*/
class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n==0) return false;
        if(n == 1)return true;
        else if(n%3 == 0) return isPowerOfThree(n/3);
        else return false;
    }
};