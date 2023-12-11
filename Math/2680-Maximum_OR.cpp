/*
題目：
https://leetcode.com/problems/maximum-or/description/

解說：
此處的 Greedy 策略是將最高位推的越遠越好，最終答案一定是最大，因此我們應該將 k 次的運算機會都給最大的元素。
但如果 nums 中有多個元素擁有相同的最高位 1，此時選擇對大元素不一定是最優解。
因此我們將每一個 nums 都嘗試推高 k 位取最大值即可。
因為透過 array 方式紀錄 32 bits 值，因此時間複雜度從 o(N^2) 降至 o(N)

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) 
    {
        vector<int> bitcnt(32);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if((nums[i] >> j) & 1)
                    bitcnt[j] ++;
            }
        }

        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            auto tmp = bitcnt;
            for(int j = 0; j < 32; j++)
            {
                if((nums[i] >> j) & 1)
                    tmp[j]--;
            }

            long long tmp_ans = 0;
            for(int j = 0; j < 32; j++)
            {
                if(tmp[j] > 0)
                    tmp_ans += (1 << j);
            }

            tmp_ans |= ((long long)nums[i] << k);
            ans = max(ans, tmp_ans);
        }

        return ans;
    }
};