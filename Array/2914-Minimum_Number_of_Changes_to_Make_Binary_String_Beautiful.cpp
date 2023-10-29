/*
題目：
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

解說：
因為題目字串長度是 even，且 substring 也是 even，因此我們只需要驗證相臨的點是否是相等即可

有使用到的觀念：
Array
*/

#include "../code_function.h"

class Solution {
public:
    int minChanges(string s) 
    {
        const int n = s.length();

        int total = 0;
        for(int i = 1; i < n; i += 2)
        {
            if(s[i] == s[i-1]) continue;
            else total++;
        }    

        return total;
    }
};