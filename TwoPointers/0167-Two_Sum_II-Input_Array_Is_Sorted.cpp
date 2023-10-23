/*
題目：
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

解說：
因為 numbers 是由小到大依序排序。
設置左指標與右指標，從邊界往內相加，直到 sum == target。
若是 sum > target ， 即代表將 r 往左移使得 sum 變小
若是 sum < target ， 即代表將 l 往右移使得 sum 變大

有使用到的觀念：
Two Pointers, Binary Search
*/
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        const int n = numbers.size();
        int l = 0, r = n-1;
        while(l < r)
        {
            if(target == numbers[l] + numbers[r]) return {l+1, r+1};
            else if(target > numbers[l] + numbers[r]) l++;
            else r--;
        }    
        return {l+1, r+1};
    }
};