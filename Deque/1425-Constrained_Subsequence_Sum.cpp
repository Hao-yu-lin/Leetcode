/*
題目：
https://leetcode.com/problems/constrained-subsequence-sum/

解說：
有兩種寫法
解法1：使用 DP
dp[i] = max{numx[i], dp[i-k]}+nums[i]}
解法2：使用 Deque

有使用到的觀念：
Deque、DP
*/

#include "../code_function.h"

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp(n);
        deque<int> dq;
        int ans = INT_MIN;
        
        for(int i = 0; i < nums.size(); ++i){
            if(i > k && dq.front() == i - k - 1) dq.pop_front();
            dp[i] = (dq.empty() ? 0 : max(dp[dq.front()], 0)) + nums[i];
            while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};