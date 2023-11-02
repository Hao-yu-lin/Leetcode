/*
題目：
https://leetcode.com/problems/simplify-path/

解說：


有使用到的觀念：
stack
*/

#include "../code_function.h"

class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string>st;
        
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == '/') continue;

            string tmp = "";

            while(i < path.size() && path[i] != '/')
            {
                tmp += path[i];
                i++;
            }

            if(tmp == ".") continue;
            else if(tmp == "..")
            {
                if(!st.empty())st.pop();
            }else
            {
                st.push(tmp);
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }

        if(ans == "") return "/";
        else return ans;
    }
};