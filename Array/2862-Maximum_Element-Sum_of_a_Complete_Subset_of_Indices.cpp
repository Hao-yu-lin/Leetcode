/*
題目：
https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/

解說：
題目要任意兩個 pos 乘積仍然是完全平方數，取該集合 nums[pos] 和的最大值
因此可以將 pos(i, j) 分解為 i = a * x^2, j = b * y^2
若該集合有其他元素 k，k = c * z^2
為了使任意兩個 pos 乘積仍為完全平方數，必須 a = b = c
因此可以窮舉成 a = 1, 2, 3, ... n

1*1, 1*4, 1*9, 1*16, ...
2*1, 2*4, 2*9, 2*16, ...
3*1, 3*4, 3*9, 3*16, ...
...
a*1, a*4, a*9, a*16, ...
...
n*1

直到元素最小 pos n
sum1 = nums[1*1] + nums[1*4] + nums[1*9] + nums[1*16] + ...
sum2 = nums[2*1] + nums[2*4] + nums[2*9] + nums[2*16] + ...
sum3 = nums[3*1] + nums[3*4] + nums[3*9] + nums[3*16] + ...

窮舉次數計算方式為
對於 a*1 有 n 次
對於 a*4 有 n/4 次
對於 a*16 有 n/16 次
因此總 total = n/1 + n/4 + n/9 + ...  < 2n


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    long long maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        int k = 1;
        long long ans = 0;

        while(k <= n)
        {
            long long sum = 0;
            for(int i = 1; k*i*i <= n; i++)
                sum += nums[k*i*i-1];
            ans = max(ans, sum);
            k++;
        }

        return ans;
    }
};