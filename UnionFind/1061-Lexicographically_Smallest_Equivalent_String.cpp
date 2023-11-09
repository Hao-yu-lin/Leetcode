/*
題目：
https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

解說：


有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<int> father;
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        father.resize(26);
        for(int i = 0; i < 26; i++)
        {
            father[i] = i;
        }

        for(int i = 0; i < s1.length(); i++)
        {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';
            if(findFather(c1) != findFather(c2))
            {
                Union(c1, c2);
            }
        }

        string ans = "";

        for(const auto& c : baseStr)
        {
            ans += findFather(father[c-'a']) + 'a';
        }

        return ans;
    }

    int findFather(int x)
    {
        if(x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }

    void Union(int x, int y)
    {
        x = findFather(x);
        y = findFather(y);
        if(x > y) father[x] = y;
        else father[y] = x;
    }
};