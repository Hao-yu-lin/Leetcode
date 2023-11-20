/*
題目：
https://leetcode.com/problems/matchsticks-to-square/description/

解說：
使用 DFS 方式遞迴每一種可能的方式

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    int n;
    long long total;
    bool visited[15];
public:
    bool makesquare(vector<int>& matchsticks) 
    {   
        n = matchsticks.size();
        
        for(int i = 0; i < n; i++)
        {
            total += matchsticks[i];
        }

        if(total%4 != 0) return false;
        else total /= 4;

        sort(matchsticks.begin(), matchsticks.end());
        return dfs(matchsticks, 0, 0, 0);
    }

    bool dfs(vector<int>& matchsticks, int cur, int group, int sum)
    {
        if(group == 4) return true;
        if(sum > total) return false;
        if(sum == total)
            return dfs(matchsticks, 0, group+1, 0);

        int last = -1;
        for(int i = cur; i < matchsticks.size(); i++)
        {
            if(visited[i] == 1) continue;
            if(matchsticks[i] == last) continue;

            visited[i] = 1;
            last = matchsticks[i];
            if(dfs(matchsticks, i+1, group, sum+matchsticks[i])) return true;
            visited[i] = 0;
        }
        return false;
    }

};