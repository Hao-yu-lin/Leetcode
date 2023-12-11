/*
題目：
https://leetcode.com/problems/count-of-matches-in-tournament/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int numberOfMatches(int n) 
    {
        if(n==1) return 0;
        if(n==2) return 1;
        if(n%2 == 0) return n/2 + numberOfMatches(n/2);
        return n/2 + numberOfMatches(n/2+1);
    }
};

