/*
題目：
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

解說：
尋找左邊界 j 與 右邊界 k，subarray 的個數為 (i-j) * (k-i)
最靠左邊的大於 nums[i] 值為左邊界，與最靠右邊的大於 nums[j] 值為右邊界

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) 
    {
        const int n = nums.size();
        
        vector<int> prevGreaterOrEqual(n, -1);
        vector<int> nextGreater(n, n);

        stack<int> stk;

        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && nums[stk.top()] < nums[i])
            {
                nextGreater[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && nums[stk.top()] <= nums[i])
            {
                prevGreaterOrEqual[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= left && nums[i] <= right)
            {
                ans += (i-prevGreaterOrEqual[i]) * (nextGreater[i] - i);
            }
        }

        return ans;
    }
};

