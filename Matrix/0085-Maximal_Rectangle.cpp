/*
題目：
https://leetcode.com/problems/maximal-rectangle/

解說：
由上至下，每一列當作底，來看當前可以成立的矩陣最大違和
for (int i=0; i<M; i++)
{
   for (int j=0; j<N; j++)
   {
      if (matrix[i][j]==0)
        q[j]=0;
      else
        q[j]=q[j]+1;
   }
}

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        const int m = matrix.size();
        const int n = matrix[0].size();

        vector<int> hist(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            }

            ans = max(ans, largestRectangleArea(hist));
        }
        return ans;
    }

    // 0084 觀念
    int largestRectangleArea(vector<int> heights)
    {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int ans = 0;
        stack<int> stk;

        for(int i = 0; i < heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int h = heights[stk.top()];
                stk.pop();
                ans = max(ans, h * (i-stk.top()-1));
            }

            stk.push(i);
        }

        return ans;
    }
};