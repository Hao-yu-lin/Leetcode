/*
題目：
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

解說：
使用 BFS 遍歷每一種可能

有使用到的觀念：

*/

#include "../code_function.h"

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size();
        int n = maze[0].size();

        int count = 0;
        queue<pair<int, int>> q; // save next location
        q.push({entrance[0], entrance[1]});

        int dir[5] = {1, 0, -1, 0, 1};
        
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty())
        {
            int size = q.size();
            count++;
            while(size--)
            {
                auto& tmp = q.front();


                int x = tmp.first;
                int y = tmp.second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int new_x = x + dir[i];
                    int new_y = y + dir[i+1];

                    if(new_x < m && new_x >= 0 && new_y < n && new_y >= 0 && maze[new_x][new_y] == '.')
                    {
                        if(new_x == 0 || new_x == m-1 || new_y == 0 || new_y == n-1) return count;
                        q.push({new_x, new_y});
                        maze[new_x][new_y] = '+';
                    }
                }
            }
        }

        return -1;
    }
};