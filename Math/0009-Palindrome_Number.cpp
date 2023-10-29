/*
題目：
https://leetcode.com/problems/palindrome-number/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x < 0 || x % 10 == 0) return false;
        
        int n = 0;

        while(n < x){
            n = n*10 + x%10;
            x = x/10;
        }

        if(x == n || x == n/10)return true;
        else return false;

    }
};