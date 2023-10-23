/*
題目：
https://leetcode.com/problems/container-with-most-water/

解說：
左右指針向中間移動，移動規則是左右較矮的板子，這樣才有使面積增大的可能。

有使用到的觀念：
Two Pointers, Array
*/
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) 
    {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while(l < r)
        {
            ans = std::max(ans, std::min(height[l], height[r]) * (r-l));
            if(height[l] > height[r]) r--;
            else l++;
        }
        return ans;
    }
};