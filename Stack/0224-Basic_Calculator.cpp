/*
題目：
https://leetcode.com/problems/basic-calculator/

解說：
使用一個 stack 作為儲存遇到 括號時的暫存空間
這邊將 - 視為負數而非減法，將全部視為相加計算
2-3 -> 2 + (-3)

有使用到的觀念：
Stack
*/

#include "../code_function.h"

class Solution {
public:
    int calculate(string s) 
    {
        long long sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        int curr = 0;
        while(curr < s.size())
        {
            if(isdigit(s[curr]))
            {
                long long num = 0;
                while(curr < s.size() && isdigit(s[curr]))
                {
                    num = num * 10 + (s[curr] - '0');
                    curr++;
                }

                sum += num * sign;
                sign = 1;
            }else if(s[curr] == '(')
            {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
                curr++;
            }else if(s[curr] == ')')
            {
                sum = st.top().first + (st.top().second * sum);
                st.pop();
                curr++;
            }else if(s[curr] == '-')
            {
                sign = -1 * sign;
                curr++;
            }else curr++;
        }
        return sum;
    }
};

