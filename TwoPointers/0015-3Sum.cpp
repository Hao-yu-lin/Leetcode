/*
題目：
https://leetcode.com/problems/3sum/

解說：
先將 nums 進行排序，考慮每一個點的組合情形。

有使用到的觀念：
Binary Search, Two Pointer
*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        for(int i = 0; i < n-2; i++)
        {
            if(i == 0 || (i>0 && nums[i] != nums[i-1]))
            {
                int left = i+1, right = n-1;
                while(left < right)
                {
                    int target = nums[i] + nums[left] + nums[right];
                    if(target == 0)
                    {
                        ans.push_back({nums[i], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(target < 0) left++;
                    else right--;
                }
                
            }
             
        }
        return ans;
    }
};