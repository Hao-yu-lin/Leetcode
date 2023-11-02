/*
題目：
https://leetcode.com/problems/permutations/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<vector<int>> ans;
    int n;
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        n = nums.size();
        vector<int> curr;
        perm(nums, curr, 0);
        return ans;
    }

    void perm(vector<int>& nums, vector<int>& curr, int index)
    {
        if(index == n)
        {
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < n; i++)
        {
            swap(nums[index], nums[i]);
            curr.push_back(nums[index]);
            perm(nums, curr, index+1);
            curr.pop_back();
            swap(nums[index], nums[i]);
        }
    }

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};