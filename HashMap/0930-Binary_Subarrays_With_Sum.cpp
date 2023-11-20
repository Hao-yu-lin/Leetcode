/*
題目：
https://leetcode.com/problems/binary-subarrays-with-sum/

解說：
解法1 hash map + prefixsum
sum[i:j] = prefix[j] - prefix[i-1]，其中 sum[i:j]==goal。
當固定 j 時，prefix[j] 則是已知的。透過期望 prefix[i-1] 多少，並且使用 ump 儲存某個所有 prefix 和 prefix[i-1] 所對應的 i 個數

解法2 sliding windows


有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        unordered_map<int, int> ump;
        ump[0] = 1;
        int prefix = 0;
        int ans = 0;

        for(int j = 0; j < nums.size(); j++)
        {
            prefix += nums[j];
            if(ump.find(prefix - goal) != ump.end())
            {
                ans += ump[prefix-goal];
            }

            ump[prefix] ++;
        }
        return ans;
    }
};

class Solution2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        const int n = nums.size();
        vector<int> postZeros(n);

        int count = 0;
        for(int i = n-1; i >= 0; i--)
        {
            postZeros[i] = count;
            if(nums[i] == 0) count++;
            else count = 0;
        }

        int j = 0, sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(j <= i || (j < n && sum < goal))
            {
                sum += nums[j];
                j++;
            }

            if(sum == goal)
                ans += postZeros[j-1]+1;
            sum -= nums[i];
        }

        return ans;
    }
};