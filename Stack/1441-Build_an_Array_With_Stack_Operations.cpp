/*
題目：
https://leetcode.com/problems/build-an-array-with-stack-operations/

解說：
如果遇到不是 target 內的數字，就 pop

有使用到的觀念：
Stack
*/

#include "../code_function.h"

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        int curr = 0;
        vector<string>ans;
        for(int i = 1; i <= n; i++)
        {
            if(curr == target.size()) break;
            ans.push_back("Push");
            if(i != target[curr])
            {
                ans.push_back("Pop");
            }else curr++;
        }

        return ans;
    }
};