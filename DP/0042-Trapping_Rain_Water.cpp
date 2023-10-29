/*
題目：
https://leetcode.com/problems/trapping-rain-water/

解說：

解法1：prefix sum
首先計算左側最大值, 與右側最大值
l[i] = max(h[0~i])  -> l[i] = max(h[i], l[i-1])
r[i] = max(h[i~n-1]) -> r[i] = max(h[i], r[i+1])

解法2：tow pointer
一個左指標，一個右指標
max_l = max(h[0:l])
max_r = max(h[r:n-1])

當 max_l < max_r：
代表使用左的高，一定可以構成水槽，因此 water += max_l - height[l]
之後左邊往右移，更新 max_l

右邊一樣概念

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution1 {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> left_max(n, -1);
        vector<int> right_max(n, -1);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        
        for(int i = 1; i < n; i++)
        {
            left_max[i] = max(left_max[i-1], height[i]);
        }

        for(int i = n-2; i >= 0; i--)
        {
            right_max[i] = max(right_max[i+1], height[i]);
        }

        int total = 0;
        for(int i = 0; i < n; i++)
        {
            total += (min(left_max[i], right_max[i]) - height[i]);
        }

        return total;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) 
    {
        const int n = height.size();
        if(n == 0) return 0;

        int l = 0;
        int r = n-1;
        int l_max = height[l];
        int r_max = height[r];

        int ans = 0;

        while(l < r)
        {
            if(l_max < r_max)
            {
                ans += l_max - height[l];
                l_max = max(l_max, height[++l]);
            }else
            {
                ans += r_max - height[r];
                r_max = max(r_max, height[--r]);
            }
        }

        return ans;
    }
};