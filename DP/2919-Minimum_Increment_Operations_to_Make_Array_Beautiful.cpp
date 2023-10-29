/*
題目：
https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

解說：
根據提意，只要全部 size = 3 的 subarray 形成 beautiful，則全部 size >= 3 皆可以形成 beautiful
因此我們只要考慮 size = 3 的全部情形。
跟據 element 的位置，我們須考慮三種情形
op1：選擇第一個 element 然後移動到下一個 subarray (idx+1)
op2：選擇第二個 element 然後移動到下下一個 subarray (idx+2) 因為下一個可以共用第二個 element
op3：選擇第三個 element 然後移動到下下下一個 subarray(idx+3) 因為下一個與下下一個可以共用第三個 element

取 op1、op2、op3 三者代價的最小值

有使用到的觀念：
DP
*/

#include "../code_function.h"

class Solution {
public:
    vector<long long> dp;
    int n;

    long long solve(int idx, vector<int>& nums, int k)
    {
        if(idx > n-3) return 0;
        if(dp[idx] != -1) return dp[idx];

        long long op1 = max(0, k-nums[idx]) + solve(idx+1, nums, k);
        long long op2 = max(0, k-nums[idx+1]) + solve(idx+2, nums, k);
        long long op3 = max(0, k-nums[idx+2]) + solve(idx+3, nums, k);

        dp[idx] = min(op1, min(op2, op3));
        return dp[idx];
    }

    long long minIncrementOperations(vector<int>& nums, int k) 
    {
        n = nums.size();  
        dp.resize(n, -1);
        return solve(0, nums,k); 
    }
};