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
#include <deque>
#include <vector>

class Solution {
public:
    int constrainedSubsetSum(std::vector<int>& nums, int k) {
        const int n = nums.size();
        std::vector<int> dp(n);
        std::deque<int> dq;
        int ans = INT_MIN;
        
        for(int i = 0; i < nums.size(); ++i){
            if(i > k && dq.front() == i - k - 1) dq.pop_front();
            dp[i] = (dq.empty() ? 0 : std::max(dp[dq.front()], 0)) + nums[i];
            while(!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
            dq.push_back(i);
            ans = std::max(ans, dp[i]);
        }

        return ans;
    }
};