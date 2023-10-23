/*
題目：
https://leetcode.com/problems/minimum-size-subarray-sum/

解說：
使用 sliding windows 方式，逐漸擴大。
當 sum < target 時，windows 最右端向右擴增
當 sum >= target 時，計算目前的大小，並且左邊的 windows 向右端縮小。

有使用到的觀念：
Sliding Windows, Array
*/
#include <vector>
#include <limits.h>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) 
    {
        const int n = nums.size();
        int startW = 0, endW = 0;
        int sum = 0;
        int ans = INT_MAX/2;
        while(endW < n)
        {
            sum += nums[endW];
            while(startW <= endW && sum >= target){
                ans = std::min(ans, endW-startW+1);
                sum -= nums[startW];
                startW++;    
            }
            endW++;
        }
        if(ans == INT_MAX/2) return 0;
        return ans;
    }
};