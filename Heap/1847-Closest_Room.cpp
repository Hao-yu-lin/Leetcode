/*
題目：
https://leetcode.com/problems/closest-room/description/

解說：
離線查詢的題目類型
對於 queries 與 rooms 依照 size 大小進行排序
從最大的 queries size 開始，將 rooms size 中符合要求 rooms ID 的放入 set 當中
透過 lower bound 方式找尋最接近的 preferred 的 rooms ID
檢查該點 與 前一個點 誰的 abs(id - preferredj) 較小

記得因為進行排序，所以已經打亂了整體的排序，必須記錄原始位置

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] > b[1];
    }
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) 
    {
        for (int i=0; i<queries.size(); i++)
            queries[i].push_back(i);
        
        sort(queries.begin(), queries.end(), cmp);        
        sort(rooms.begin(), rooms.end(), cmp);
        
        
        int curr_room = 0;
        set<int> s;

        vector<int> res(queries.size(), -1);
        for(auto &q: queries)
        {
            while(curr_room < rooms.size() && rooms[curr_room][1] >= q[1])
            {
                s.insert(rooms[curr_room][0]);
                curr_room++;
            }

            int ans = -1;
            int diff = INT_MAX;
            auto iter = s.lower_bound(q[0]);

            if(iter != s.end())
            {
                if(*iter - q[0] < diff)
                {
                    diff = *iter - q[0];
                    ans = *iter;
                }
            }

            if(iter != s.begin())
            {
                iter = prev(iter, 1);
                if(abs(*iter - q[0]) <= diff)
                {
                    diff = abs(*iter - q[0]);
                    ans = *iter;
                }
            }

            res[q[2]] = ans;
        }
        return res;
    }
};