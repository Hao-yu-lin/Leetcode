/*
題目：
https://leetcode.com/problems/course-schedule-ii/

解說：
與 0207 一樣。差別只是在 最後的回傳是陣列還是 bool

有使用到的觀念：
BFS
*/

#include "../code_function.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for(int i = 0; i < numCourses; i++)
        {
            graph[i] = {};
            indegree[i] = 0;
        }

        for(const auto& p : prerequisites)
        {
            int prefix = p[1];
            int course = p[0];

            indegree[course] ++;
            graph[prefix].push_back(course);
        }

        vector<int> finish;
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();

            finish.push_back(tmp);
            for(const auto& c : graph[tmp])
            {
                indegree[c]--;
                if(indegree[c] == 0) q.push(c);
            }
        }

        if(finish.size() == numCourses) return finish;
        else return {};
    }
};