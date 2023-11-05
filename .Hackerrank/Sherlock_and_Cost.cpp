/*
題目：
https://www.hackerrank.com/challenges/sherlock-and-cost/problem

解說：
求陣列中相鄰 element 的絕對值差之和，為了使相鄰數相差最大，相鄰必須分別取最大值和最小值，不能同時取最大值
dp[i][1] = max(dp[i-1][0] + abs(B[i] - 1), dp[i-1][1] + abs(B[i] - B[i-1])) 第 i 元素取最大值 
dp[i][0] = max(dp[i-1][0], dp[i-1][1] + abs(B[i-1]-1));  第 i 元素取最小值

有使用到的觀念：

*/

#include "../code_function.h"

int cost(vector<int> B) 
{
    const int n = B.size();
    int prev_0 = 0, prev_1 = 0;
    int ans0 = 0, ans1 = 0;
    for(int i = 1; i < n ; ++i){
        ans0 = max(prev_0+abs(B[i]-B[i-1]), prev_1+abs(1-B[i]));
        ans1 = prev_0 + abs(1 - B[i-1]);
        prev_0 = ans0;
        prev_1 = ans1;
    }
    return max(ans0, ans1);
}