/*
題目：
https://leetcode.com/problems/sum-of-subarray-minimums/

解說：
prev：位於 i 的左邊第一個比 arr[i] 小的數
next：位於 i 的右邊第一個比 arr[i] 小的數

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    const int M = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        const int n = arr.size();

        vector<int> prev(n, -1);
        vector<int> next(n, n);

        stack<int> stk;

        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && arr[stk.top()] > arr[i])
            {
                next[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i])
            {
                prev[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            long count = ((i-prev[i]) * (next[i]-i))%M;
            
            ans = (ans + arr[i]*count)%M;
        }

        return ans;
    }
};