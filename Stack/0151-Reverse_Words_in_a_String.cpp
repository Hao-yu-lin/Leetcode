/*
題目：
https://leetcode.com/problems/reverse-words-in-a-string/

解說：
這邊使用 stack 儲存每一個單字。
利用 stack 的 Last In First Out 特性，可以快速的將單字倒放

有使用到的觀念：
Stack
*/

#include "../code_function.h"

class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string> st;
        string tmp = "";
        for(const char& c : s)
        {
            if(c == ' ')
            {
                if(tmp != "")
                {
                    st.push(tmp);
                    tmp = "";
                }
            }else
            {
                tmp += c;
            }
        }
        if(tmp != "") st.push(tmp);

        string ans ="";

        if(!st.empty())
        {
            ans += st.top();
            st.pop();
        }else return "";
        
        while(!st.empty())
        {
            ans += ' ';
            ans += st.top();
            st.pop();
            
        }
        return ans;

    }
};