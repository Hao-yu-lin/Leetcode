/*
題目：
https://leetcode.com/problems/find-unique-binary-string/

解說：
進行排序，從頭開始依序尋找，當發現有缺漏就回傳答案

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        string curr = "";
        for(int i = 0; i < n; i++)
        {
            curr += "0";
        }

        for(auto s : nums)
        {
            if(curr != s) return curr;
            else update(curr);
        }
        return curr;
    }

    void update(string& curr)
    {
        char pre = '1';
        int n = curr.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(curr[i] == '0')
            {
                curr[i] = pre;
                return;
            }else if(curr[i] == '1' && pre == '0')
            {
                return;
            }else if(curr[i] == '1' && pre == '1')
            {
                curr[i] = '0';
                pre = '1';
            }
        }
    }
};