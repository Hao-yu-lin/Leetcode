/*
題目：
https://leetcode.com/problems/count-number-of-homogenous-substrings/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int mod = 1000000007;
public:
    int countHomogenous(string s) 
    {
        long long ans = 0;
        int start = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != s[start])
            {
                int appear = i - start;
                while(appear > 0)
                {
                    ans += appear;
                    appear--;
                    ans = ans%mod;
                }
               
                start = i;
            }
        }

        int appear = s.size() - start;
        while(appear > 0)
        {
            ans += appear;
            ans = ans%mod;
            appear--;
        }

        return ans%mod;
    }
};