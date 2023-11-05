/*
題目：
https://leetcode.com/problems/keys-and-rooms/

解說：
使用 queue 紀錄手上持有的鑰匙，使用 visited 紀錄是否有拜訪過

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        const int n = rooms.size();
        vector<int> visited(n, 0);

        queue<int> q;

        for(const auto& k : rooms[0])
        {
           q.push(k);
        }
        visited[0] = 1;
        if(q.empty()) return false;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int keys = q.front();
                q.pop();
                if(visited[keys] != 0) continue;
                visited[keys] = 1;

                for(const auto& k : rooms[keys])
                {
                    if(visited[k] == 0) q.push(k);
                }
            }
        }

        for(const auto& c : visited)
        {
            if(c == 0) return false;
        }

        return true;
    }
};