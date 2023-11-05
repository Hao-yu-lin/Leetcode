/*
題目：
https://leetcode.com/problems/kth-largest-element-in-an-array/

解說：
使用 max heap，而且排序是由小排到大，因此當大小超過 k 時，就刪除最前端的

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(const auto& c : nums)
        {
            pq.push(c);
            if(pq.size() > k)
            {
                pq.pop();
            }
        }

        return pq.top();
    }
};