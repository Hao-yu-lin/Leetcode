/*
題目：
https://leetcode.com/problems/climbing-stairs/

解說：
一次只能移動一格或兩格，因此今日若要移動到 i 格，可以從 i-1 格一次移動到 i 或是從 i-2 格一次移動到 i。
需注意起始值，i = 1 時步數為 1，i = 2 時步數為 2。

有使用到的觀念：
DP, Fibonacci
*/

#include "../code_function.h"

class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> stair(50, 0);
        stair[1] = 1;
        stair[2] = 2;

        for(int i = 3; i <= n; i++){
            stair[i] = stair[i-1] + stair[i-2];
        }

        return stair[n];
    }
};

