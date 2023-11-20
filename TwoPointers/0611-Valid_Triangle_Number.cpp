/*
題目：
https://leetcode.com/problems/valid-triangle-number/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int triangleNumber(vector<int>& nums) 
    {
        const int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        

        int ans = 0;
        for(int k = 2; k < n; k++)
        {
            int left = 0;
            int right = k-1;
            while(left < right)
            {
                if(nums[left] + nums[right] > nums[k])
                {
                    ans += right - left;
                    right --;
                }else left ++;
            }
        }

        return ans;
    }
};