/*
題目：
https://leetcode.com/problems/similar-string-groups/

解說：
透過 set 方式先將重複的組合給排除掉後，再透過 union find 來進行合併相似的集合

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    vector<int> father;
public:
    int numSimilarGroups(vector<string>& strs) 
    {
        unordered_set<string>B(strs.begin(), strs.end());
        strs.clear();
        for(auto x : B)
        {
            strs.push_back(x);
        }
        int n = strs.size();
        father.resize(n);

        for(int i = 0; i < n; i++)
            father[i] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isSimilar(i, j, strs) && findFather(i) != findFather(j)) Union(i, j);
            }
        }

        unordered_set<int> s;
        for(int i = 0; i < n; i++)
            s.insert(findFather(i));
        return s.size();
    }

    int findFather(int x)
    {
        if(x != father[x])
            father[x] = findFather(father[x]);
        return father[x];
    }

    void Union(int x, int y)
    {
        x = father[x];
        y = father[y];

        if(x < y)
            father[y] = x;
        else
            father[x] = y;
    }

    bool isSimilar(int x, int y, vector<string>& strs)
    {   

        int count = 0;
        for(int i = 0; i < strs[x].length(); i++)
        {
            if(strs[x][i] != strs[y][i])
            {
                count += 1;
            }
        }

        return count == 2;
    }
};