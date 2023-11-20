/*
題目：
https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int total;
    bool visited[16];
public:
    bool canPartitionKSbsets(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        total = accumulate(nums.begin(), nums.end(), 0);

        if(total%k != 0) return false;
        return dfs(nums, k, 0, 0, 0);
    }

    bool dfs(vector<int>& nums, int k, int idx, int group, int sum)
    {
        if(group == k) return true;
        if(sum > total/k) return false;
        if(sum == total/k) return dfs(nums, k, 0, group+1, 0);
        int last = -1;
        for(int i = idx; i < nums.size(); i++)
        {
            if(visited[i]==true) continue;
            if(nums[i] == last) continue;
            last = nums[i];
            visited[i] = true;
            if(dfs(nums, k, i, group, sum+nums[i])) return true;
            visited[i] = false;
        }

        return false;
    }
};