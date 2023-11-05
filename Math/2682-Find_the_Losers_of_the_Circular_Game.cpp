/*
題目：
https://leetcode.com/problems/find-the-losers-of-the-circular-game/

解說：
使用一個 vector 紀錄接到球的人，一但有人重複接到就結束遊戲

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) 
    {
        vector<int>people(n, 0);
        int curr = 0;
        int i = 1;
        while(1)
        {
            if(people[curr] == 1) break;
            people[curr] = 1;
            curr = (curr + i*k)%n;
            i++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(people[i] == 0) ans.push_back(i+1);
 
        }
        return ans;
    }
};