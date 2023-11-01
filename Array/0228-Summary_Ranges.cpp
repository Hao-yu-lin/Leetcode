/*
題目：
https://leetcode.com/problems/summary-ranges/

解說：
設計 begin 與 end 兩個指標，因為他已經 sort ，所以可以讓 end 與前一個字進行比較
如果不是差距為 1 則代表不連續，則將 begin 到 end-1 這區間值放入 ans 中，然後再把起點換成 end，end 往下檢查

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        const int n = nums.size();
        if(n == 0) return {};
        vector<string> ans;
        int begin = 0;
        int end = 1;

        while(end < n)
        {
            if(nums[end-1]+1 != nums[end])
            {
                if(begin != end-1){
                    string tmp = to_string(nums[begin]) + "->" + to_string(nums[end-1]);
                    ans.push_back(tmp);
                    begin = end;
                }else{
                    string tmp = to_string(nums[begin]);
                    ans.push_back(tmp);
                    begin = end;
                }
            }
            end++;
        }

        if(begin != end-1){
            string tmp = to_string(nums[begin]) + "->" + to_string(nums[end-1]);
            ans.push_back(tmp);
            begin = end;
        }else{
            string tmp = to_string(nums[begin]);
            ans.push_back(tmp);
            begin = end;
        }

        return ans;
    }
};