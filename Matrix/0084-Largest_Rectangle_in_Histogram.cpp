/*
題目：
https://leetcode.com/problems/largest-rectangle-in-histogram/description/

解說：
solution1
3 - pass
leftSmaller 代表左側第一個小於 height[i]
rightSmaller 代表右側第一個小於 height[i]
求出每一個高的 leftSmaller 與 rightSmaller 後
針對每一個高計算面積
area[i] = height[i]*(rightSmaller[i]-leftSmaller[i]-1)

solution2
使用一組 stack，當 heights[stack.top()] < heights[i] 時
此時 stack 中的 top 為 rightSmaller
而下一個 top 為 leftSmaller


有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        const int n = heights.size();

        stack<int> stk;

        vector<int>rightSmaller(n, n);
        for(int i = 0; i < n; i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                rightSmaller[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();
        vector<int>leftSmaller(n, -1);
        for(int i = n-1; i >= 0; i--)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                leftSmaller[stk.top()] = i;
                stk.pop();
            }

            stk.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (rightSmaller[i] - leftSmaller[i] - 1));
        return ans;

    }
};

class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        stack<int> stk;
        int result = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int h = heights[stk.top()];
                stk.pop();
                result = max(result, h * (i - stk.top() - 1));
            }

            stk.push(i);
        }

        return result;
    }
};