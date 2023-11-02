/*
題目：
https://leetcode.com/problems/evaluate-reverse-polish-notation/

解說：
因為他是 Reverse Polish notation，所以假設 3 * 4 -> 3 4 *
因此可以依序將遇到的 string 放入 stack 中，如果要放入的是 + - * / 則將 stack.top 兩個取出，進行運算後，再放回 stack 中

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;

        for(auto& w : tokens)
        {
            if(w == "+" || w == "-" || w == "*" || w == "/")
            {
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();
                if(w == "+") st.push(first + second);
                else if(w == "-") st.push(first - second);
                else if(w == "*") st.push(first * second);
                else st.push(first / second);
            }else st.push(stoi(w));
        }

        return st.top();
    }
};