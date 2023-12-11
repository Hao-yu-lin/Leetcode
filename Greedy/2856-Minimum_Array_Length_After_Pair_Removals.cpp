/*
題目：
https://leetcode.com/problems/minimum-array-length-after-pair-removals/

解說：
本題使用到的是 Boyer-Moore Majority Voting Algorithm，當存在一個超過半數的 majority 時，其他元素聯合起來並不能消除
因此當存在一個超過半數的 majority 時，消除次數為 f，剩餘的元素為 n-f
每個其他元素消滅一個 majoiry 元素，剩下的就是 n - (n-f)*2

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++)
        {
            ump[nums[i]] ++;
        }

        int mx = 0;

        for(auto [k, v]:ump)
            mx = max(mx, v);

        if(mx > n/2)
            return n - (n-mx)*2;
        else
            return n%2;
    }
};