/*
題目：
https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

解說：
因為題目數字最大只到 50000，因此建立一個陣列，計算每一個的出現頻率
之後陣列由後往前計算 operation

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        const int n = nums.size();
        vector<int> freq(50001, 0);

        for(int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        int ans = 0;
        int operate = 0;

        for(int i = 50000;  i >= 1; i--)
        {
            if(freq[i] > 0)
            {
                operate += freq[i];
                ans += operate - freq[i];
            }
        }

        return ans;
    }
};