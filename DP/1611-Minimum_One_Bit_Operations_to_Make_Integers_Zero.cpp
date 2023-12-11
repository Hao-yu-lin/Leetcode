/*
題目：
https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/

解說：
1(xxxxx) -> 1(10000) -> 0(10000) -> 0(00000)

有使用到的觀念：

*/

#include "../code_function.h"

class Solution1 {
    unordered_map<string, int> ump;
    unordered_map<string, int> ump2;
public:
    int minimumOneBitOperations(int n) 
    {
        string str = bitset<32>(n).to_string();
        return dfs(str);
    }

    int dfs(string n)
    {
        if(n == "0") return 0;
        if(n == "1") return 1;
        if(ump.find(n) != ump.end()) return ump[n];

        if(n[0] == '0') return dfs(n.substr(1));

        string m = n.substr(1);
        string p = m;
        p[0] = '1';
        for(int i = 1; i < p.size(); i++)
            p[i] = '0';
        ump[n] = dfs2(m) + 1 + dfs(p);
        return ump[n];
    }

    int dfs2(string n)
    {
        if(n == "0") return 1;
        if(n == "1") return 0;
        if(ump2.find(n) != ump2.end()) return ump2[n];

        if(n[0] == '1')
            ump2[n] = dfs(n.substr(1));
        else
        {
            string m = n.substr(1);
            string p = m;
            p[0] = '1';
            for(int i = 1; i < p.size(); i++)
                p[i] = '0';
            ump2[n] = dfs2(m) + 1 + dfs(p);
        }

        return ump2[n];
    }
};