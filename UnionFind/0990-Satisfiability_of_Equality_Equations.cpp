/*
題目：
https://leetcode.com/problems/satisfiability-of-equality-equations/

解說：
搜尋兩次，先搜尋 == ，將全部 == 分類成同一個集合，再重新搜尋一次將 != 檢查是否有矛盾

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<int> Father;
public:
    bool equationsPossible(vector<string>& equations) 
    {
        Father.resize(26);
        for(int i = 0; i < 26; i++)
        {
            Father[i] = i;
        }

        for(const auto& eq : equations)
        {
            if(eq[1] == '=')
            {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';

                if(findFather(a) != findFather(b)) Union(a, b);
            }
        }

        for(const auto& eq : equations)
        {
            if(eq[1] == '!')
            {
                int a = eq[0] - 'a';
                int b = eq[3] - 'a';

                if(findFather(a) == findFather(b)) return false;
            }
        }
        return true;
    }

    int findFather(int x)
    {
        if(x != Father[x])
            Father[x] = findFather(Father[x]);
        return Father[x];
    }

    void Union(int a, int b)
    {
        a = Father[a];
        b = Father[b];
        if(a < b) Father[b] = a;
        else Father[a] = b;
    }
};