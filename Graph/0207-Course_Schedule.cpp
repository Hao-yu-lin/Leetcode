/*
題目：
https://leetcode.com/problems/course-schedule/

解說：
使用一個 hash map 紀錄，課程之間的關係圖，使用一個 hash map 紀錄該門課的前置課程還有多少
設立一個 queue ，將前置課程為 0 的值放入 queue 中，再從課程關係圖中，刪減該門課解鎖的其他課程。

有使用到的觀念：
BFS
*/

#include "../code_function.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for(int i = 0; i < numCourses; i++)
        {
           indegree[i] = 0;
           graph[i] = {}; 
        }

        for(const auto& c : prerequisites)
        {
            int preq = c[1];
            int cour = c[0];

            graph[preq].push_back(cour);
            indegree[cour] ++;
        }

        queue<int> q;
        for(const auto& p : indegree)
        {
            if(p.second == 0)
            {
                q.push(p.first);
            }
        }

        vector<int> finish;

        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();

            finish.push_back(tmp);
            for(const int c : graph[tmp])
            {
                indegree[c]--;
                if(indegree[c] == 0){
                    q.push(c);
                }
            }
        }

        return finish.size() == numCourses;
        
    }
};