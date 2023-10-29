/*
題目：
https://leetcode.com/problems/find-the-k-or-of-an-array/

解說：


有使用到的觀念：
Bit operation
*/

#include "../code_function.h"

class Solution {
public:
    int findKOr(vector<int>& nums, int k) 
    {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            int cnt = 0;
            for(auto x : nums)
            {
                if((1 << i)&x) cnt++;
            }

            if(cnt >= k) ans += (1 << i);
        }    

        return ans;
    }
};