/*
題目：
https://leetcode.com/problems/valid-parentheses/

解說：


有使用到的觀念：
stack
*/

#include "../code_function.h"

class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(const auto& c : s)
        {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else{
                if(c == ')')
                {
                    if(!st.empty() && st.top() == '(')st.pop();
                    else return false;
                }else if(c == '}')
                {
                    if(!st.empty() && st.top() == '{')st.pop();
                    else return false;
                }else
                {
                    if(!st.empty() && st.top() == '[')st.pop();
                    else return false;
                }
            }
        }

        if(st.empty()) return true;
        else return false;
    }
};