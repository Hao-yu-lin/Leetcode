/*
題目：
https://leetcode.com/problems/4sum/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < n-3; i++)
        {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            long long target_1 = target - nums[i];
            for(int j = i+1; j < n-2; j++)
            {
                if(j > i+1 and nums[j] == nums[j-1]) continue;
                long long new_target = target_1 - nums[j];
                int left = j+1;
                int right = n-1;
                while(left < right)
                {
                    int sum = nums[left] + nums[right];
                    if(new_target == sum){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left<right and nums[left] == nums[left+1]) left++;
                        while(left<right and nums[right] == nums[right-1]) right--;
                    
                        left++;
                        right--;
                    }
                    
                    else if(new_target > sum)
                    {
                        left ++;
                    }else{
                        right --;
                    }
                }
            }
        }
        return ans;
    }
};